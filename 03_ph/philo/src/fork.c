/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:26:28 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 04:33:07 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo/fork.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

t_bool	fork_pool_create(t_simulation *sim)
{
	t_i32	i;

	i = -1;
	sim->fpool = malloc(sizeof(t_fork) * sim->nphilosophers);
	if (!sim->fpool)
		return (printf("!sim->fpool: malloc()\n") == 0);
	memset(sim->fpool, 0, sizeof(t_fork) * sim->nphilosophers);
	while (++i < sim->nphilosophers)
	{
		if (pthread_mutex_init(&sim->fpool[i].mtx, NULL))
			return (printf("pthread_mutex_init()\n") == 0);
	}
	return (TRUE);
}

void	fork_pick(t_fork *frk)
{
	pthread_mutex_lock(&frk->mtx);
}

void	fork_drop(t_fork *frk)
{
	pthread_mutex_unlock(&frk->mtx);
}
