/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:46:35 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/29 09:46:35 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_bool	init_philo_n_forks(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nums)
	{
		data->philo[i].id = i + 1;
		data->philo[i].status = THINKING;
		data->philo[i].is_full = FALSE;
		data->philo[i].eat_cnt = 0;
		data->philo[i].data = data;
		data->philo[i].lfork = &(data->mforks[i]);
		if (i + 1 == data->philo_nums)
			data->philo[i].rfork = &(data->mforks[0]);
		else
			data->philo[i].rfork = &(data->mforks[i + 1]);
		if (pthread_mutex_init(data->mforks + i, NULL) != SUCCESS)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	malloc_philo_n_forks(t_data *data)
{
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->philo_nums);
	if (!(data->philo))
		return (FALSE);
	data->mforks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->philo_nums);
	if (!(data->forks))
	{
		free(info->philo);
		return (FALSE);
	}
	return (init_philo_n_forks(data));
}

t_bool	init_mutex(t_data *data)
{
	if (pthread_mutex_init(&(data->mmain), NULL) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_init(&(data->mprint), NULL) != SUCCESS)
		return (FALSE);
	if (pthread_mutex_init(&(data->mdead), NULL) != SUCCESS)
		return (FALSE);
	pthread_mutex_lock(&(data->mmain));
	return (TRUE);
}

t_bool	init_data(t_data *data, int ac, int *av_nums)
{
	data->philo_nums = av_nums[0];
	data->ttdie = av_nums[1];
	data->tteat = av_nums[2];
	data->ttsleep = av_nums[3];
	if (ac != 6)
		data->must_eat = -1;
	else
		data->must_eat = av_nums[4];
	data->full = 0;
	data->end = FALSE;
	if (!malloc_philo_n_forks(data))
		return (print_error("Fail to init forks"));
	if (!init_mutex(data))
		return (print_error("Fail to init mutex"));
	return (TRUE);
}
