/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/28 14:02:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

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
		g_server.pid = info->si_pid;
		g_server.msg = ft_strdup("");
		g_server.act.sa_sigaction = hdr_msg;
		sigaction(SIGUSR1, &(g_server.act), NULL);
		sigaction(SIGUSR2, &(g_server.act), NULL);
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
	ft_kill(g_server.pid, SIGUSR1);
	if (bit == 0)
	{
		if (c != '\0')
			g_server.msg = ft_join(g_server.msg, c);
		else
		{
			ft_putstr(g_server.msg);
			free(g_server.msg);
			g_server.act.sa_sigaction = hdr_connection;
			sigaction(SIGUSR1, &(g_server.act), NULL);
			sigaction(SIGUSR2, &(g_server.act), NULL);
			ft_kill(info->si_pid, SIGUSR2);
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
	g_server.act.sa_flags = SA_SIGINFO;
	g_server.act.sa_sigaction = hdr_connection;
	sigemptyset(&(g_server.act.sa_mask));
	sigaction(SIGUSR1, &(g_server.act), NULL);
	sigaction(SIGUSR2, &(g_server.act), NULL);
	print_pid();
	while (TRUE)
		pause();
	return (0);
}
