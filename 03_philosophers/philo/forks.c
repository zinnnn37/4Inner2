/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:26 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/10 18:14:16 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	init_forks(t_data *data)
{
	int	i;

	data->forks = calloc(data->nums, sizeof(t_mutex));
	if (!(data->forks))
		return (print_error("Fail to allocate memory: data->forks"));
	i = -1;
	while (++i < data->nums)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (print_error("Fail to initialize mutex: data->forks"));
	}
	return (TRUE);
}

void	pick_fork(t_mutex *fork)
{
	pthread_mutex_lock(&fork);
	display_msg(philo, FORK_MSG);
}

void	put_fork(t_mutex *fork)
{
	pthread_mutex_unlock(&fork);
}
