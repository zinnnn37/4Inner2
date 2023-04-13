/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:51:14 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 11:19:56 by minjinki         ###   ########.fr       */
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

void	destroy_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_destroy(&(data->philos[i]->meal));
		pthread_mutex_destroy(&(data->mforks[i]));
	}
	pthread_mutex_destroy(&(data->mprint));
	pthread_mutex_destroy(&(data->mdead));
}

// void	free_data(t_data *data)
// {
// 	int	i;

// 	if (data->mforks)
// 		free(data->mforks);
// 	if (data->philos)
// 	{
// 		i = -1;
// 		while (++i < data->num_philos)
// 			free(data->philos[i]);
// 		free(data->philos);
// 	}
// }
