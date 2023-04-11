/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 04:10:43 by marousta          #+#    #+#             */
/*   Updated: 2021/12/23 04:29:57 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <common/types.h>
#include <common/utils.h>
#include <philo/simulation.h>
#include <philo/philosopher.h>
#include <stdio.h>
#include <strings.h>

static t_bool	check_died(t_simulation *sim, t_pphilo phi)
{
	t_i32	i;

	i = -1;
	printf("%zu %u died\n", get_now() / TIMESTAMP_DIV, phi->id + 1);
	while (++i < sim->nphilosophers)
		sim->philosophers[i].is_alive = FALSE;
	philo_unlock(phi);
	return (TRUE);
}

static t_bool	check_satisfied(t_simulation *sim, t_bool *psatisfied, t_i32 *i)
{
	t_i32	x;

	x = -1;
	*i = 0;
	if (sim->ntimes_phil_eat >= 0 && *psatisfied)
	{
		while (++x < sim->nphilosophers)
			sim->philosophers[x].is_alive = FALSE;
		return (FALSE);
	}
	*psatisfied = TRUE;
	return (TRUE);
}

void	simulation_wait_for_end(t_simulation *sim)
{
	t_pphilo	phi;
	t_i32		i;
	t_bool		psatisfied;
	t_u64		now;

	i = 0;
	psatisfied = TRUE;
	while (TRUE)
	{
		now = get_now();
		phi = &sim->philosophers[i++];
		philo_lock(phi);
		if (now > phi->last_eat_ts + sim->time_to_die && check_died(sim, phi))
			break ;
		if (sim->ntimes_phil_eat >= 0 && phi->n_eat < sim->ntimes_phil_eat)
			psatisfied = FALSE;
		philo_unlock(phi);
		if (i >= sim->nphilosophers && !check_satisfied(sim, &psatisfied, &i))
			break ;
	}
	simulation_join(sim);
}
