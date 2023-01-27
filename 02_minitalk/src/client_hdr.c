/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_hdr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:14:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/27 12:13:17 by minjinki         ###   ########.fr       */
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
		
	}
}

void	c_hdr_bits(int signo, siginfo_t *info, void *content)
{
}