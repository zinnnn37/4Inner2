/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:12:24 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/27 12:12:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) != 0)
		print_error("Kill failed");
	else
		usleep(100);
}
