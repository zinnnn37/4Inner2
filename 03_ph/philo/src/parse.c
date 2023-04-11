/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:35:56 by marousta          #+#    #+#             */
/*   Updated: 2021/12/23 04:07:25 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philosopher.h>
#include <philo/simulation.h>
#include <common/utils.h>
#include <stdlib.h>
#include <stdio.h>

static t_bool	parse_num(t_simulation *sim, t_string *av)
{
	t_i32	n;

	if (!ft_satoi(&n, av[1]) || n < 1)
		return (FALSE);
	sim->nphilosophers = n;
	if (!ft_satoi(&n, av[2]) || n < 1)
		return (FALSE);
	sim->time_to_die = n * 1000;
	if (!ft_satoi(&n, av[3]) || n < 1)
		return (FALSE);
	sim->time_to_eat = n * 1000;
	if (!ft_satoi(&n, av[4]) || n < 1)
		return (FALSE);
	sim->time_to_sleep = n * 1000;
	return (TRUE);
}

t_bool	simulation_init(t_simulation *sim, t_i32 ac, char **av)
{
	t_i32	n;

	if (!parse_num(sim, av))
		return (FALSE);
	sim->ntimes_phil_eat = -1;
	if (ac == 6)
	{
		if (!ft_satoi(&n, av[5]) || n < 1)
			return (FALSE);
		sim->ntimes_phil_eat = n;
	}
	sim->philosophers = malloc(sizeof(t_philo) * sim->nphilosophers);
	if (!sim->philosophers)
		return (printf("sim->philosophers: malloc()\n") == 0);
	if (!fork_pool_create(sim))
		return (printf("fork_pool_create()\n") == 0);
	philo_create(sim);
	return (TRUE);
}
