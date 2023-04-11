/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:00:54 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 04:33:36 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <common/types.h>
#include <philo/simulation.h>
#include <philo/philosopher.h>
#include <common/utils.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>

void	display_state(t_pphilo phi, char *s)
{
	philo_lock(phi);
	if (phi->is_alive)
		printf("%zu %u %s\n", get_now() / TIMESTAMP_DIV, phi->id + 1, s);
	philo_unlock(phi);
}

t_i32	main(t_i32 ac, char **av)
{
	t_simulation	sim;

	if (ac != 5 && ac != 6)
		return (printf("Usage: philo <num philosophers> <...>\n") != 0);
	memset(&sim, 0, sizeof(t_simulation));
	if (!simulation_init(&sim, ac, av))
		return (printf("Usage: philo <num philosophers> <...>\n") != 0);
	simulation_begin(&sim);
	simulation_wait_for_end(&sim);
	simulation_destroy(&sim);
	return (EXIT_SUCCESS);
}
