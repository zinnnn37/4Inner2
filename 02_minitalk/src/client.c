/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:22 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 20:04:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_cdata;

void	print_pid(void)
{
	ft_putstr_fd("Client PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

void	c_hdr_msg(int signo, siginfo_t *info, void *content)
{
}

void	c_hdr_connect(int signo)
{
	kill(g_cdata.pid, signo);
	pause();
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		print_error("Check input format: ./client server_PID message\n");
	g_client.sa_flags = SA_SIGINFO;
	g_client.__sigaction_u.__sa_sigaction = c_hdr_connect;
	sigemptyset(&g_client.sa_mask);
	sigaction(SIGUSR1, &g_client, NULL);
	sigaction(SIGUSR2, &g_client, NULL);
	g_cdata.pid = ft_atoi(argv[1]);
	if (g_cdata.pid == -1)
		print_error("Check if PID is number: ./client server_PID message\n");
	g_cdata.msg = argv[2];
	print_pid();
	c_hdr_connect(SIGUSR1);
}
