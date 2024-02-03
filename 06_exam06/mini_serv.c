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

fd_set	activefds, readfds, writefds;

char	buf[200000], msg[200000], str[200000];

void	ft_exit(int code, char *s, int fd)
{
	if (code == 2)
		close(fd)
	write(2, s, strlen(s));
	exit(1);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		ft_exit(1, "Wrong number of arguments\n", 0);
	
	serverSoc = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSoc == -1)
		ft_exit(1, "Fatal error\n", serverSoc);

	struct	sockaddr_in serverAddr;

	bzero(&serverAddr, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(atoi(av[1]));
	serverAddr.sin_addr.s_addr = htonl(16777343);

	if ((bind(serverSoc, (struct sockaddr *)&serverAddr, sizeof(serverAddr))) == -1)
		ft_exit(2, "Fatal error\n", serverSoc);
	if ((listen(serverSoc, MAX_CLI)) == -1)
		ft_exit(2, "Fatal error\n", serverSoc);
	

}