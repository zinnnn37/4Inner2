#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char *s;

    while ((s = get_next_line(1)))
    {
        printf("%s\n", s);
        free(s);
    }
    return 0;
}