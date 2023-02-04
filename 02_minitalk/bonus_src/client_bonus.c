/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:22 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/04 12:07:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/minitalk_bonus.h"

void	print_pid(void)
{
	ft_putstr("===============  BONUS  ===============\n\n");
	ft_putstr("Client PID : ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
}

void	send_bits(char c)
{
	int	bit;
	int	check;

	bit = 7;
	while (bit >= 0)
	{
		check = 1 << bit;
		if (c & check)
			ft_kill(g_cdata.pid, SIGUSR1);
		else
			ft_kill(g_cdata.pid, SIGUSR2);
		bit--;
	}
}

void	send_msg(void)
{
	static int	i = 0;
	static int	bits = 8;

	while (g_cdata.msg[i])
	{
		send_bits(g_cdata.msg[i]);
		i++;
	}
	if (g_cdata.msg[i] == '\0')
	{
		send_bits('\n');
		while (bits-- > 0)
			ft_kill(g_cdata.pid, SIGUSR2);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		print_error("Check input format: ./client server_PID message\n");
	if (ft_atoi(argv[1], &pid) == 0)
		print_error("Check if PID is number\n");
	g_cdata.pid = pid;
	g_cdata.msg = argv[2];
	g_cdata.act.sa_flags = SA_SIGINFO;
	g_cdata.act.sa_sigaction = c_hdr_connection;
	sigemptyset(&(g_cdata.act.sa_mask));
	sigaction(SIGUSR1, &(g_cdata.act), NULL);
	sigaction(SIGUSR2, &(g_cdata.act), NULL);
	print_pid();
	ft_kill(g_cdata.pid, SIGUSR1);
	while (TRUE)
		pause();
	return (0);
}
