/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_hander.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:55:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 20:03:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	c_hdr_msg(int signo, siginfo_t *info, void *content)
{
}

void	c_hdr_connect(int signo)
{
	kill(g_cdata)
}
