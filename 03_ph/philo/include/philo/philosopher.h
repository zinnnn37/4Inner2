/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:38:30 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 04:27:06 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# ifdef DISPLAY_MS
#  define TIMESTAMP_DIV 1000
# else
#  define TIMESTAMP_DIV 1
# endif

# include <common/types.h>
# include <philo/simulation.h>
# include <pthread.h>
# include <philo/fork.h>

typedef enum e_philostate {
	PHILO_STATE_UNKNOWN,
	PHILO_STATE_EATING,
	PHILO_STATE_SLEEPING,
	PHILO_STATE_THINKING,
}	t_philostate;

typedef struct s_philosopher {
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_simulation	*sim;
	t_usize			creation_ts;
	t_usize			last_eat_ts;
	t_u32			id;
	t_i32			n_eat;
	t_bool			is_alive;
	t_philostate	state;
	pthread_t		thread;
	pthread_mutex_t	mtx;
}t_philo,*t_pphilo;

void	philo_init(t_pphilo phi, t_u32 id, t_simulation *sim);
void	philo_create(t_simulation *sim);
void	philo_destroy(t_pphilo phi);

void	philo_lock(t_pphilo phi);
void	philo_unlock(t_pphilo phi);

void	philo_eat(t_pphilo phi);
void	philo_think(t_pphilo phi);
void	philo_sleep(t_pphilo phi);

void	philo_live(t_pphilo phi);
void	philo_print_state(t_pphilo phi);
void	display_state(t_pphilo phi, char *s);

#endif
