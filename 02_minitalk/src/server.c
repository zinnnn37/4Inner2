/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/17 11:47:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int n);

void	print_pid(void)
{
	ft_putstr("Server PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

void	s_hdr_msg(int signo, siginfo_t *info, void *content)
{
	static unsigned char	c;
	static int				bit = 8;

	(void)content;
	if (signo == SIGUSR1)
		c += (1 << --bit);
	else if (signo == SIGUSR2)
		bit--;
	if (bit == 0)
	{
		write(1, &c, 1);
		c = '\0';
		bit = 8;
	}
}

void	hdr_connection(int signo, siginfo_t *info, void *content)
{
	(void)content;
	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		ft_putstr("Client PID : ")
		ft_putnbr(siginfo->si_pid);
		ft_putchar('\n');
		g_data.act.sa_sigaction = hdr_msg;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		if (kill(info.si_pid, signo) != 0)
			print_error("Connection failed\n");
		else
			usleep(100);
	}
	else
		print_error("Connection failed\n");
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		print_error("Check input format: ./server\n");
	g_data.act.sa_flags = SA_SIGINFO;
	g_data.act.sa_sigaction = hdr_connection;
	sigemptyset(&act.sa_mask);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	print_pid();
	while (TRUE)
		pause();
	return (0);
}
