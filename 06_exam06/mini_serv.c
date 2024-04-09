#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

fd_set	readfds, writefds, allfds;
int		maxfd, clientid, serversocket;
int		clients[FD_SETSIZE];
char	buf[400000];

void	fatal(char *str)
{
	write(2, str, strlen(str));
	exit(1);
}

void	broadcast(int sender)
{
	for (int fd = 3; fd <= maxfd; ++fd)
	{
		if (FD_ISSET(fd, &writefds) && fd != sender)
			if (send(fd, buf, strlen(buf), 0) < 0)
				fatal("Fatal error\n");
	}

	bzero(&buf, sizeof(buf));
}

int	main(int ac, char **av)
{
	int					clientSocket;
	struct sockaddr_in	serveraddr, clientaddr;
	socklen_t			clientaddr_len = sizeof(clientaddr);

	if (ac != 2)
		fatal("Wrong number of arguments\n");

	serversocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serversocket == -1)
		fatal("Fatal error\n");

	bzero(&serveraddr, sizeof(serveraddr));

	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	serveraddr.sin_port = htons(atoi(av[1]));

	if ((bind(serversocket, (const struct sockaddr *)&serveraddr, sizeof(serveraddr))) != 0)
		fatal("Fatal error\n");
	if (listen(serversocket, 10) != 0)
		fatal("Fatal error\n");

	maxfd = serversocket;
	FD_ZERO(&allfds);
	FD_SET(serversocket, &allfds);

	while(1)
	{
		readfds = allfds;
		writefds = allfds;
	
		if (select(maxfd + 1, &readfds, &writefds, 0, 0) < 0)
			continue;

		if (FD_ISSET(serversocket, &readfds))
		{
			clientSocket = accept(serversocket, (struct sockaddr *)&clientaddr, &clientaddr_len);
			if (clientSocket < 0)
				continue;

			FD_SET(clientSocket, &allfds);
			clients[clientSocket] = clientid;
			maxfd = maxfd < clientSocket ? clientSocket : maxfd;

			sprintf(buf, "server: client %d just arrived\n", clientid++);
			broadcast(clientSocket);

			continue;
		}
		for (int fd = 3; fd <= maxfd; ++fd)
		{
			if (FD_ISSET(fd, &readfds))
			{
				int		ret = 1;
				char	msg[400000];

				bzero(&msg, sizeof(msg));

				while (ret == 1 && msg[strlen(msg) - 1] != '\n')
					ret = recv(fd, msg + strlen(msg), 1, 0);
				
				if (ret <= 0)
				{
					sprintf(buf, "server: client %d just left\n", clients[fd]);
					FD_CLR(fd, &allfds);
					close(fd);
				}
				else
					sprintf(buf, "client %d: %s", clients[fd], msg);

				broadcast(fd);
			}
		}
	}
	return (0);
}
