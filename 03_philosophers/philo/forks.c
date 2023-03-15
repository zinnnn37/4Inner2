/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:26 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/10 14:10:26 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_forks(t_data *data)
{
	int	i;

	data->forks = calloc(data->nums, sizeof(t_fork));
	if (!(data->forks))
		return (print_error("Fail to allocate memory: data->forks"));
	i = -1;
	while (++i < data->nums)
	{
		if (pthread_mutex_init(&data->forks[i].mtx, NULL))
			return (print_error("Fail to initialize mutex: data->forks.mtx"));
	}
	return (TRUE);
}

void	pick_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx);
}

void	put_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mtx);
}
