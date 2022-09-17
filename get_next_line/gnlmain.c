#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *s;
	while (1)
	{
		s = get_next_line(1);
		printf("test: %s", s);
	}
	return (0);
}
