/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:51:14 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/12 09:51:14 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_cur_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	do_usleep(t_data *data, time_t time)
{
	time_t	end;

	end = get_cur_time() + time;
	while (get_cur_time() < time)
	{
		if (is_simul_stopped(data))
			return ;
		usleep(100);
	}
}

void	run_delay(time_t start)
{
	while (get_cur_time() < start)
		continue ;
}
