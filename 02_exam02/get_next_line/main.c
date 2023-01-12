#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    char *s;
    int fd;

    fd = open("hi", O_RDONLY);
    while (1)
    {
        s = get_next_line(fd);
        printf("%s", s);
        if (strcmp(s, "") == 0)
            break ;
        free(s);
    }
    return 0;
}