/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:36:21 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/13 16:56:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** get current time: gap from start time
*/
size_t	get_cur_time(void)
{
	static time_t	start = 0;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (start == 0)
		start = tv.tv_sec * 1000000 + tv.tv_usec;
	return ((tv.tv_sec * 1000000) + (tv.tv_usec) - start);
}

void	do_usleep(size_t time)
{
	size_t	start;

	start = get_cur_time();
	while (get_cur_time() - start < time)
		usleep(50);
}
