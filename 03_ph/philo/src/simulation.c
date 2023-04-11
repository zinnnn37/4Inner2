/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:55:06 by marousta          #+#    #+#             */
/*   Updated: 2023/04/11 15:00:19 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <common/types.h>
#include <common/utils.h>
#include <philo/simulation.h>
#include <philo/philosopher.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

typedef void *	(*t_threadfunc)(void * _);

void	simulation_destroy(t_simulation *sim)
{
	t_i32	i;

	i = -1;
	while (++i < sim->nphilosophers)
	{
		philo_destroy(&sim->philosophers[i]);
	}
	free(sim->philosophers);
	free(sim->fpool); //
}

void	simulation_begin(t_simulation *sim)
{
	t_i32	i;

	i = -1;
	while (++i < sim->nphilosophers)
	{
		pthread_create(&sim->philosophers[i].thread, NULL,
			(t_threadfunc) & philo_live, &sim->philosophers[i]);
	}
}

void	simulation_join(t_simulation *sim)
{
	t_i32	i;

	i = -1;
	while (++i < sim->nphilosophers)
	{
		pthread_join(sim->philosophers[i].thread, NULL);
	}
}

//