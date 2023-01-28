/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:12:24 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/28 18:42:22 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus_include/minitalk_bonus.h"

void	ft_kill(pid_t pid, int signo)
{
	if (kill(pid, signo) != 0)
		print_error("Kill failed");
	else
		usleep(100);
}
