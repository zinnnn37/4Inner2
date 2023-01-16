/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:01:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 19:50:02 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	s_hdr_msg(int signo, siginfo_t *info, void *content)
{
	static unsigned char	c;
	static int				bit = 8;

	(void)content;
	if (signo == SIGUSR1)
		c += 1 << --bit;
	else if (signo == SIGUSR2)
		bit--;
	if (bit == 0)
	{
		write(1, &c, 1);
		c = '\0';
		bit = 8;
	}
}

void	s_hdr_connect(int signo, siginfo_t *info, void *content)
{
}
