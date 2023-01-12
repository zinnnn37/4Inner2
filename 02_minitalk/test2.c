#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char **argv)
{
	if (argc < 2)
		printf("Usage: ./%s PID \n", argv[0]);
	else
		kill(atoi(argv[1]), 9); // 9 == 강제종료
}