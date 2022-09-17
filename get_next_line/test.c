#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "get_next_line.h"
/*
int main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
}
*/

int main(void)
{
	static t_list *head;
	
	printf("%p\n", head); // 하.. 0 나오네...
	return (0);
}