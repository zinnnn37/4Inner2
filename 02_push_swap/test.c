#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("%d\n\n", argc);
	for (int i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}