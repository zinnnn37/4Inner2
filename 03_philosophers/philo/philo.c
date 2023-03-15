/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:29:59 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/13 17:58:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* init philo struct */
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
	// fork
	// if (id == odd)	philo->state = EATING;
	// if (id == data->nums - 1)
//	{
		//philo->lfork = &data->fork[id];
		//philo->rfork = &data->fork[0];
//	}
	// thread
	// mtx
	if (philo->id == data->nums - 1)
	{
		philo->lfork = &data->fork[id];
		philo->rfork = &data->fork[0];
	}
}

void	create_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		init_philo(&data->philos[i], i, data);
}
