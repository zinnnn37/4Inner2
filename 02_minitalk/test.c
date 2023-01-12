#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct two_words { int a, b, c; } memory;

void handler(int signum) { printf ("%d %d %d\n", memory.a, memory.b, memory.c); }

int main (int argc, char **argv)
{
	// pid data race
//    static struct two_words zeros = { 0, 0, 0 }, ones = { 1, 1, 1 };
//    signal (SIGUSR1, handler);
//    memory = zeros;
//    printf("pid : %d\n", getpid());
//    while (1) {
//       memory = zeros;
//       memory = ones;
//    }


	// print unicode
	// for (int i = 0; argv[1][i]; i++)
	// 	printf("%c\n", argv[1][i]); // \n으로 분리하면 문자열 깨짐
	// printf("return : ");
	// for (int i = 0; argv[1][i]; i++)
	// 	printf("%c", argv[1][i]);	// \n으로 구분하지 않을 시 유니코드 바이트에 따라 알아서 표시
	// printf("\n");
	// return (0);


	//kill by test2.c
	// int i = 10;
	// printf("%d\n", getpid());
	// printf("Count down\n");
	// while (i >= 0)
	// {
	// 	printf("%d sec\n", i);
	// 	sleep(1);
	// 	i--;
	// }
}