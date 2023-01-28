/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_hdr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:14:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/28 14:04:00 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

void	c_hdr_bits(int signo, siginfo_t *info, void *content);

void	c_hdr_connection(int signo, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (signo == SIGUSR1)
	{
		ft_putstr("Connection succeed\n");
		g_client.act.sa_sigaction = c_hdr_msg;
		sigaction(SIGUSR1, &(g_client.act), NULL);
		sigaction(SIGUSR2, &(g_client.act), NULL);
		send_msg();
	}
	else if (signo == SIGUSR2)
		print_error("Connection failed\n");
	else
		print_error("Unknown signal: should use SIGUSR1 and SIGUSR2 only\n");
}

void	c_hdr_msg(int signo, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (g_client.bit != 0 && signo != SIGUSR1)
		print_error("Signal missed\n");
	// g_client.act.sa_sigaction = c_hdr_end;
	// sigaction(SIGUSR1, &(g_client.act), NULL);
	// sigaction(SIGUSR2, &(g_client.act), NULL);
}

void	c_hdr_end(int signo, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (signo == SIGUSR2)
	{
		ft_putstr("Message sent successfully\n");
//		system("leaks client");
		exit(0);
	}
	else
		print_error("Fail to send message\n");
}
