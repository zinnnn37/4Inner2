#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 200000

int max_fd, client_id;

fd_set all_fds;
fd_set read_fds;
fd_set write_fds;

int client_ids[FD_SETSIZE];

char *read_buf;
char write_buf[BUFFER_SIZE];

int extract_message(char **buf, char **msg)
{
    char *next;
    int i;

    *msg = 0;
    if (*buf == 0)
        return (0);
    i = 0;
    while ((*buf)[i])
    {
        if ((*buf)[i] == '\n')
        {
            next = calloc(strlen(*buf + i + 1) + 1, sizeof(char));
            strcpy(next, *buf + i + 1);
            *msg = *buf;
            (*msg)[i + 1] = 0;
            *buf = next;
            return (1);
        }
        i++;
    }
    return (0);
}

void exit_with_error(char *str)
{
    write(2, str, strlen(str));
    exit(1);
}

void fatal_error()
{ 
    exit_with_error("Fatal error\n");
}

void send_to_all(char *msg, int sender_fd)
{
    for (int fd = 0; fd <= max_fd; fd++)
    {
        if (FD_ISSET(fd, &write_fds) && fd != sender_fd)
            send(fd, msg, strlen(msg), 0);
    }
}

int main(int argc, char **argv)
{
    int servfd, clientfd;
    struct sockaddr_in servaddr;

    if (argc != 2)
        exit_with_error("Usage: ./mini_serv port\n");

    // socket create and verification
    servfd = socket(AF_INET, SOCK_STREAM, 0);
    if (servfd == -1)
        fatal_error();

    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(atoi(argv[1]));

    // Binding newly created socket to given IP and verification
    if ((bind(servfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
        fatal_error();

    if (listen(servfd, 10) != 0)
        fatal_error();

    max_fd = servfd;
    FD_SET(servfd, &all_fds);

    while (1)
    {
        read_fds = all_fds;
        write_fds = all_fds;
        
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) == -1)
            continue;

        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &read_fds))
            { // read할 수 있는 fd
                if (fd == servfd)
                { // server socket인 경우
                // accept_client();
                    clientfd = accept(servfd, NULL, NULL);
                    if (clientfd < 0)
                        continue;

                    FD_SET(clientfd, &all_fds);
                    if (clientfd > max_fd)
                        max_fd = clientfd;

                    client_ids[clientfd] = client_id++;

                    sprintf(write_buf, "server: client %d just arrived\n", client_ids[clientfd]);
                    send_to_all(write_buf, clientfd);
                }
                else
                { // client socket인 경우
                    read_buf = calloc(BUFFER_SIZE, sizeof(char));

                    if (recv(fd, read_buf, BUFFER_SIZE, 0) <= 0)
                    { // client가 나간 경우
                    // disconnect_client();
                        FD_CLR(fd, &all_fds);
                        FD_CLR(fd, &read_fds);
                        FD_CLR(fd, &write_fds);
                        close(fd);

                        sprintf(write_buf, "server: client %d just left\n", client_ids[fd]);
                        send_to_all(write_buf, fd);
                    }
                    else
                    { // client가 메시지를 보낸 경우
                        // send_message(read_buf);
                        char *msg = NULL;
                            
                        while (extract_message(&read_buf, &msg))
                        {
                            sprintf(write_buf, "client %d: %s", client_ids[fd], msg);
                            send_to_all(write_buf, fd);
                            free(msg);
                        }
                    }
                    free(read_buf);
                }
            }
        }
    }
}