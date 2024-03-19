#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int		MAX_CLI = 128;
int		serverSoc = -1;
int		maxSoc = 0;
int		id = 0;
int		clients[100000], newMsg[100000];

fd_set	activefds, readyfds, writefds;

char	buf[200000], msg[200000], str[200000];

void	ft_exit(int code, char *s, int fd)
{
	if (code == 2)
		close(fd);
	write(2, s, strlen(s));
	exit(1);
}

void broadcast(int i)
{
	for (int j = 0; j <= maxSoc; j++)
	{
		if (FD_ISSET(j, &writefds) && j != i)
			send(j, msg, strlen(msg), 0);
	}
}

void	disconnectClient(int i)
{
	sprintf(msg, "server: client %d just left\n", clients[i]);
	broadcast(i);
	FD_CLR(i, &activefds);
	close(i);
}

void	handleMsg(int soc, int buff)
{
	for (int i = 0, j = 0; i < buff; i++, j++)
	{
		str[j] = buf[i];

		if (buf[i] == '\n')
		{
			str[j + 1] = '\0';

			if (newMsg[soc])
				sprintf(msg, "%s", str);
			else
				sprintf(msg, "client %d: %s", clients[soc], str);

			newMsg[soc] = 0;
			broadcast(soc);

			j = -1;
		}
		else if (i == buff - 1)
		{
			str[j + 1] = '\0';

			if (newMsg[soc])
				sprintf(msg, "%s", str);
			else
				sprintf(msg, "client %d: %s", clients[soc], str);

			newMsg[soc] = 1;
			broadcast(soc);

			break ;
		}
	}
}

int acceptClient(int i)
{
	struct		sockaddr_in clientAddr;
	socklen_t	clientAddrLen = sizeof(clientAddr);

	int	newSoc = accept(i, (struct sockaddr *)&clientAddr, &clientAddrLen);
	
	if (newSoc == -1)
		return 1;

	FD_SET(newSoc, &activefds);

	clients[newSoc] = id++;
	newMsg[newSoc] = 0;

	if (newSoc > maxSoc)
		maxSoc = newSoc;

	sprintf(msg, "server: client %d just arrived\n", clients[newSoc]);

	broadcast(i);
	return 0;
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_exit(1, "Wrong number of arguments\n", 0);
	
	struct	sockaddr_in serverAddr;

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = 16777343;
	serverAddr.sin_port = htons(atoi(av[1]));

	serverSoc = socket(AF_INET, SOCK_STREAM, 0);

	if (serverSoc == -1)
		ft_exit(1, "Fatal error\n", serverSoc);
	if ((bind(serverSoc, (const struct sockaddr *)&serverAddr, sizeof(serverAddr))) != 0)
		ft_exit(2, "Fatal error\n", serverSoc);
	if ((listen(serverSoc, MAX_CLI)) != 0)
		ft_exit(2, "Fatal error\n", serverSoc);

	bzero(clients, sizeof(clients));
	FD_ZERO(&activefds);
	FD_SET(serverSoc, &activefds);
	maxSoc = serverSoc;

	while (1)
	{
		readyfds = activefds;
		writefds = activefds;

		if (select(maxSoc + 1, &readyfds, &writefds, NULL, NULL) <= 0)
			continue ;
		
		for (int i = 0; i <= maxSoc; i++)
		{
			if (FD_ISSET(i, &readyfds))
			{
				if (i == serverSoc)
				{
					if (acceptClient(i))
						continue ;
					else
						break ;
				}
				else
				{
					int	buff = recv(i, buf, 200000, 0);
					if (buff <= 0)
					{
						disconnectClient(i);
						break ;
					}
					else
						handleMsg(i, buff);
				}
			}
		}
	}

	return 0;
}