#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
/*
int main(int argc, char **argv)
{
	if (argc < 2)
		printf("Usage: ./%s PID \n", argv[0]);
	else
		kill(atoi(argv[1]), 9); // 9 == 강제종료
}
*/


int main(void)
{
	int	bit = 7;
	int shift;
	char c = 'A';

	while (bit >= 0)
	{
		shift = 1 << bit;
		if (c & shift)
			printf("1 ");
		else
			printf("0 ");
	}
}