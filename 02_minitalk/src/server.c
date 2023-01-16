/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 19:58:27 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_sdata;

void	print_pid(void)
{
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		print_error("Check input format: ./server\n");
	g_server.sa_flags = SA_SIGINFO;
	g_server.__sigaction_u.__sa_sigaction = s_hdr_connect;
	sigemptyset(&g_server.sa_mask);
	sigaction(SIGUSR1, &g_server, NULL);
	sigaction(SIGUSR2, &g_server, NULL);
	print_pid();
	while (TRUE)
		pause();
}
