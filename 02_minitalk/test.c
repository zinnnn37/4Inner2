/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 16:10:42 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 16:13:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
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
*/

/*
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct	sigaction	act_sigusr1;
struct	sigaction	act_sigusr1_prev;

void sigusr1_handler(int signo)
{
	printf("sigusr1 signal\n");
	sigaction(SIGUSR1, &act_sigusr1, &act_sigusr1_prev);
}

int main( void)
{
	pid_t	pid;

	pid = getpid();
	act_sigusr1.sa_handler = sigusr1_handler;
	sigemptyset(&act_sigusr1.sa_mask);                                      

	sigaction(SIGUSR1, &act_sigusr1, &act_sigusr1_prev); 
	
	printf("pid: %d\n", pid);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR1);

	printf("bye\n");
	return (0);
}
*/

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct	sigaction	act_new;
struct	sigaction	act_prev;

struct	sigaction	act_sigusr1;
struct	sigaction	act_sigusr1_prev;

int		resting;

void sigint_handler(int signo)
{
   printf("Ctrl-C(SIGINT) received!!\n");
   //printf("Press Ctrl-C again to terminate process.\n");
   //sigaction(SIGINT, &act_prev, NULL);
   //printf("You'll not see me anymore. bye. :(\n");
   resting += 1;
   resting *= -1;
}

void sigusr1_handler(int signo)
{
	printf("sigusr1 signal\n");
}

int main( void)
{
	pid_t	pid;

	pid = getpid();
	act_new.sa_handler = sigint_handler;
	act_sigusr1.sa_handler = sigusr1_handler;
	sigemptyset( &act_new.sa_mask);
	sigemptyset(&act_sigusr1.sa_mask);
	
	printf("pid: %d\n", pid);
	sigaction(SIGINT, &act_new, NULL); 
	sigaction(SIGUSR1, &act_sigusr1, NULL); 
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR1);
	while(!resting)
	{
		printf( "running...\n");
		sleep(1);
	}
	while(resting)
	{
		printf("Well I'll go get some rest. Ho-hum\n");
		pause();
		printf("Did you wake me up?\n");
	}
	printf("bye\n");
	return (0);
}
