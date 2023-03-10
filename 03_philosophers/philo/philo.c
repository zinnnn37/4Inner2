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
void	philo_init(t_philo *philo, int id, t_data *data)
{
	// get_cur_time();
	// philo->last_eat = get_cur_time();
	// philo->id = id
	// philo->state = SLEEPING;
	// if (id == odd)	philo->state = EATING;
	// philo->data = data;
	// philo->eat_count = 0;
	// philo->is_dead = FALSE;
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
		philo_init(&data->philo[i], i, data);
}
