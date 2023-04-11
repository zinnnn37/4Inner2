/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:11:18 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 04:31:46 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <common/types.h>

struct	s_philosopher;
struct	s_fork;

typedef struct s_simulation {
	t_i32					nphilosophers;
	t_i32					time_to_eat;
	t_i32					time_to_sleep;
	t_i32					time_to_die;
	t_i32					ntimes_phil_eat;
	struct s_fork			*fpool;
	struct s_philosopher	*philosophers;
}	t_simulation;

t_bool	simulation_init(t_simulation *sim, t_i32 ac, char **av);
void	simulation_destroy(t_simulation *sim);
void	simulation_begin(t_simulation *sim);
void	simulation_join(t_simulation *sim);
void	simulation_wait_for_end(t_simulation *sim);

#endif
