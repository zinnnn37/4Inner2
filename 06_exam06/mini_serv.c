#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/select.h>

fd_set	readfds, writefds, activeSockets; // Sockets sets
int		clients[FD_SETSIZE]; //Array of clients' IDs
int		fdMax = 0, idNext = 0, serverSocket = 0; // Maximum socket descriptor, Identifier for the next client connection and server socket
char	buffer[400000];	// Buffer used for message exchange

// Print error message on standard error and then exit
void	ftError(char *str)
{
	if (serverSocket > 2)
		close(serverSocket);
	write(2, str, strlen(str));
	exit(1);
}

// Send the message stored in buffer to all the clients except for the one identified by clientSocket
void	sendAll(int clientSocket)
{
	for (int fd = 3; fd <= fdMax; ++fd)
	{
		if (FD_ISSET(fd, &writefds) && fd != clientSocket)
			if (send(fd, buffer, strlen(buffer), 0) < 0)
				ftError("Fatal error\n");
	}

	bzero(&buffer, sizeof(buffer));
}

int	main(int ac, char **av)
{
	int					clientSocket;
	struct sockaddr_in	servaddr, clientaddr;
	socklen_t			clientaddr_len = sizeof(clientaddr);

	if (ac == 1)
		ftError("Wrong number of arguments\n");
	bzero(&buffer, sizeof(buffer));
	serverSocket = socket(AF_INET, SOCK_STREAM, 0); 
	if (serverSocket == -1)
		ftError("Fatal error\n");
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); // Set the IP address to localhost
	servaddr.sin_port = htons(atoi(av[1]));
	if ((bind(serverSocket, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		ftError("Fatal error\n");
	if (listen(serverSocket, 10) != 0)
		ftError("Fatal error\n");


	fdMax = serverSocket;
	FD_ZERO(&activeSockets); // Initialise the active sockets set
	FD_SET(serverSocket, &activeSockets); // Add the server socket to the set

	while(1)
	{
		readfds = writefds = activeSockets;
	
		if (select(fdMax + 1, &readfds, &writefds, 0, 0) < 0)
			continue;

		if (FD_ISSET(serverSocket, &readfds))
		{
			clientSocket = accept(serverSocket, (struct sockaddr *)&clientaddr, &clientaddr_len);
			if (clientSocket < 0)
				continue;

			FD_SET(clientSocket, &activeSockets); // Add the client socket to the set of active sockets
			clients[clientSocket] = idNext; // Add the client socket to the array

			sprintf(buffer, "server: client %d just arrived\n", idNext);
			sendAll(clientSocket);

			fdMax = clientSocket > fdMax ? clientSocket : fdMax; // Update the maximum socket descriptor
			idNext++;

			continue;
		}
		for (int fd = 3; fd <= fdMax; ++fd) // Check each socket for activity
		{
			if (FD_ISSET(fd, &readfds))
			{
				int		res = 1;
				char	msg[400000];

				bzero(&msg, sizeof(msg));

				while(res == 1 && msg[strlen(msg) - 1] != '\n')
					res = recv(fd, msg + strlen(msg), 1, 0); // Receive data from the client
				
				if (res <= 0) // Notify remaining clients about the disconnected client
				{// Close the socket and remove it from the active set
					sprintf(buffer, "server: client %d just left\n", clients[fd]);
					FD_CLR(fd, &activeSockets);	// Remove the client socket from the set of active sockets	
					close(fd);
				}
				else //Broadcast the received message to all other clients
					sprintf(buffer, "client %d: %s", clients[fd], msg);

				sendAll(fd);
			}
		}
	}
	return (0);
}
