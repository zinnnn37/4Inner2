#include <fcntl.h>
#include <stdio.h>
#include "./get_next_line.h"

int	main(void)
{
	int fd = open("a.txt", O_RDONLY);
	char	*s;

	while (1)
	{
		s = get_next_line(fd);
		printf("%s\n", s);
	}
}