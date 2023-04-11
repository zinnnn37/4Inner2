/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:27:30 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/16 19:05:54 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

# include <common/types.h>
# include <philo/simulation.h>
# include <pthread.h>

typedef struct s_fork {
	pthread_mutex_t	mtx;
}	t_fork;

t_bool	fork_pool_create(t_simulation *sim);
void	fork_pick(t_fork *frk);
void	fork_drop(t_fork *frk);

#endif
