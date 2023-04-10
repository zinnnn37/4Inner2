/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:29:59 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/10 18:33:27 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
**init philo struct
*/
void	init_philo(t_philo *philo, int id, t_data *data)
{
	philo->id = id;
	philo->state = SLEEPING;
	if (id % 2 == 1)
		philo->state = EATING;
	philo->is_dead = FALSE;
	philo->start_time = get_cur_time();
	philo->last_eat = philo->start_time;
	philo->eat_cnt = 0;
	philo->data = data;
	if (id == data->nums - 1)
	{
		philo->lfork = &data->forks[id];
		philo->rfork = &data->forks[0];
	}
	else
	{
		philo->lfork = &data->forks[id];
		philo->rfork = &data->forks[id + 1];
	}
	if (pthread_mutex_init(&philo->mtx, NULL))
		print_error("Fail to initialize mutex: philo->mtx");
}

void	create_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		init_philo(&data->philos[i], i, data);
	// ..
}

void	lock_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->mtx);
}

void	unlock_philo(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mtx);
}
