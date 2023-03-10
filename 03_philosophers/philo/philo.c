/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:29:59 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/10 14:29:59 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* init philo struct */
void	init_philo(t_philo *philo, int id, t_data *data)
{
	philo->philo_id = id;
	philo->state = SLEEPING;
	philo->is_dead = FALSE;
	philo->start_time = get_cur_time(); // create func
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
}

void	philo_create(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philos)
		init_philo(&data->philo[i], i, data);
}
