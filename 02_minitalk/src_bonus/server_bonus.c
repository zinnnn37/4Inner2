/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/27 16:21:13 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	hdr_msg(int signo, siginfo_t *info, void *content);

void	print_pid(void)
{
	ft_putstr("Server b PID : ");
	ft_putnbr(getpid());
	write(1, "\n\n", 2);
}

void	hdr_connection(int signo, siginfo_t *info, void *content)
{
	(void)content;
	if (signo == SIGUSR1 || signo == SIGUSR2)
	{
		ft_putstr("Client PID : ");
		ft_putnbr(info->si_pid);
		write(1, "\n\n", 2);
		ft_putstr("Messgae : ");
		g_sdata.pid = info->si_pid;
		g_sdata.msg = ft_strdup("");
		g_sdata.act.sa_sigaction = hdr_msg;
		sigaction(SIGUSR1, &(g_sdata.act), NULL);
		sigaction(SIGUSR2, &(g_sdata.act), NULL);
		ft_kill(info->si_pid, signo);
	}
	else
		print_error("Connection failed\n");
}

void	hdr_msg(int signo, siginfo_t *info, void *content)
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
		if (c != '\0')
			g_sdata.msg = ft_join(g_sdata.msg, c);
		else
		{
			ft_putstr(g_sdata.msg);
			free(g_sdata.msg);
			ft_putstr("\n================================================\n\n");
			g_sdata.act.sa_sigaction = hdr_connection;
			sigaction(SIGUSR1, &(g_sdata.act), NULL);
			sigaction(SIGUSR2, &(g_sdata.act), NULL);
			ft_kill(info->si_pid, signo);
		}
		bit = 8;
		c = '\0';
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		print_error("Check input format: ./server\n");
	g_sdata.act.sa_flags = SA_SIGINFO;
	g_sdata.act.sa_sigaction = hdr_connection;
	sigemptyset(&(g_sdata.act.sa_mask));
	sigaction(SIGUSR1, &(g_sdata.act), NULL);
	sigaction(SIGUSR2, &(g_sdata.act), NULL);
	print_pid();
	while (TRUE)
		pause();
	return (0);
}
