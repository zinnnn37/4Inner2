/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:40:23 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 14:50:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_simul_stopped(t_data *data)
{
	t_bool	flag;

	flag = FALSE;
	pthread_mutex_lock(&(data->mdead));
	if (data->end == TRUE)
		flag = TRUE;
	pthread_mutex_unlock(&(data->mdead));
	return (flag);
}

void	set_end_flag(t_data *data, int status)
{
	pthread_mutex_lock(&(data->mdead));
	data->end = status;
	pthread_mutex_unlock(&(data->mdead));
}

t_bool	is_philo_dead(t_philo *philo)
{
	time_t	time;

	time = get_cur_time();
	if ((time - philo->last_eat) >= philo->data->ttdie)
	{
		msg(philo, "died");
		set_end_flag(philo->data, TRUE);
		pthread_mutex_unlock(&(philo->meal));
		return (TRUE);
	}
	return (FALSE);
}

t_bool	should_be_ended(t_data *data)
{
	int		i;
	t_bool	end;

	end = TRUE;
	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_lock(&(data->philos[i]->meal));
		if (is_philo_dead(data->philos[i]))
			return (TRUE);
		if (data->must_eat != -1)
			if (data->philos[i]->eat_count < data->must_eat)
				end = FALSE;
		pthread_mutex_unlock(&(data->philos[i]->meal));
	}
	if (data->must_eat != -1 && end == TRUE)
	{
		set_end_flag(data, TRUE);
		return (TRUE);
	}
	return (FALSE);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	if (data->must_eat == 0)
		return (NULL);
	set_end_flag(data, FALSE);
	while (TRUE)
	{
		if (should_be_ended(data))
			break ;
		usleep(100);
	}
	return (NULL);
}
