/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_hdr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:14:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/27 14:01:45 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	c_hdr_bits(int signo, siginfo_t *info, void *content);

void	c_hdr_connection(int signo, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (signo == SIGUSR1)
	{
		ft_putstr("Connection succeed\n");
		g_cdata.act.sa_sigaction = c_hdr_bits;
		sigaction(SIGUSR1, &(g_cdata.act), NULL);
		sigaction(SIGUSR2, &(g_cdata.act), NULL);
		send_msg();
	}
	else if (signo == SIGUSR2)
		print_error("Connection failed\n");
	else
		print_error("Unknown signal: should use SIGUSR1 and SIGUSR2 only\n");
}

void	c_hdr_bits(int signo, siginfo_t *info, void *content)
{
	(void)info;
	(void)content;
	if (signo == SIGUSR2)
	{
		ft_putstr("Message sent successfully\n");
		exit(0);
	}
	else
		print_error("Fail to send message\n");
}
