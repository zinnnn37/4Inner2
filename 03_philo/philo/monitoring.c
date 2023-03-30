/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:17:30 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/30 13:53:50 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	monitor_eating(t_data *data)
{
	if (data->full == data->philo_nums)
	{
		if (pthread_mutex_lock(&(data->mprint)) == SUCCESS)
		{
			pthread_mutex_lock(&(data->mmain));
			return (TRUE);
		}
		return (FALSE);
	}
	return (TRUE);
}

t_bool	monitor_dead(t_data *data, int i)
{
	if (get_time() - data->philo[i].die_cnt > data->ttdie)
	{
		if (pthread_mutex_lock(&(data->mdead)) == SUCCESS)
		{
			data->philo[i].status = DEAD;
			print_msg(&(data->philo[i]), DEAD_MSG);
			data->end = TRUE;
			usleep(100);
			pthread_mutex_unlock(&(data->mmain));
			return (TRUE);
		}
		return (TRUE);
	}
	return (FALSE);
}

void	*monitoring(void *d)
{
	int		i;
	t_data	*data;

	data = (t_data *)d;
	i = 0;
	while (TRUE)
	{
		if (data->end)
			return ((void *)SUCCESS);
		if (i == data->philo_nums)
			i = 0;
		if (!monitor_eating(data))
			return ((void *)FALSE);
		if (monitor_dead(data, i))
			return ((void *)TRUE);
		i++;
		usleep(100);
	}
}
