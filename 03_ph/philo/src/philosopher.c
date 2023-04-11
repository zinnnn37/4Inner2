/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:49:44 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 04:09:14 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philosopher.h>
#include <philo/simulation.h>
#include <philo/fork.h>
#include <common/utils.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

void	philo_init(t_pphilo phi, t_u32 id, t_simulation *sim)
{
	phi->creation_ts = get_now();
	phi->last_eat_ts = phi->creation_ts;
	phi->id = id;
	phi->state = PHILO_STATE_SLEEPING;
	if (id & 0b1)
		phi->state = PHILO_STATE_EATING;
	phi->sim = sim;
	phi->n_eat = 0;
	phi->is_alive = TRUE;
	if ((t_i32)id == sim->nphilosophers - 1)
	{
		phi->left_fork = &sim->fpool[id];
		phi->right_fork = &sim->fpool[0];
	}
	else
	{
		phi->left_fork = &sim->fpool[id];
		phi->right_fork = &sim->fpool[id + 1];
	}
	if (pthread_mutex_init(&phi->mtx, NULL))
		write(2, "Error while creating thread\n", 28);
}

void	philo_create(t_simulation *sim)
{
	t_i32	i;

	i = -1;
	while (++i < sim->nphilosophers)
	{
		philo_init(&sim->philosophers[i], i, sim);
	}
}

void	philo_destroy(t_pphilo phi)
{
	if (phi->state == PHILO_STATE_UNKNOWN) //? 진짜 unknown이네..
		return ;
	pthread_mutex_destroy(&phi->mtx);
}

void	philo_lock(t_pphilo phi)
{
	pthread_mutex_lock(&phi->mtx);
}

void	philo_unlock(t_pphilo phi)
{
	pthread_mutex_unlock(&phi->mtx);
}
