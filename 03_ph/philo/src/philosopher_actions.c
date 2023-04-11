/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:43:37 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 16:06:19 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <philo/philosopher.h>
#include <common/utils.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

void	philo_live(t_pphilo phi)
{
	while (phi->is_alive)
	{
		if (phi->state == PHILO_STATE_SLEEPING)
			philo_sleep(phi);
		else if (phi->state == PHILO_STATE_EATING)
			philo_eat(phi);
		else if (phi->state == PHILO_STATE_THINKING)
			philo_think(phi);
	}
}

static t_bool	one_philo_fix(t_pphilo phi)
{
	if (phi->sim->nphilosophers == 1)
	{
		fork_drop(phi->right_fork);
		while (phi->is_alive)
			usleep(5);
		return (FALSE);
	}
	return (TRUE);
}

void	philo_eat(t_pphilo phi)
{
	if ((phi->id & 0b1) == 1)
	{
		fork_pick(phi->left_fork);
		display_state(phi, "has taken a fork");
		fork_pick(phi->right_fork);
		display_state(phi, "has taken a fork");
	}
	else
	{
		fork_pick(phi->right_fork);
		display_state(phi, "has taken a fork");
		if (!one_philo_fix(phi))
			return ;
		fork_pick(phi->left_fork);
		display_state(phi, "has taken a fork");
	}
	display_state(phi, "is eating");
	ft_usleep(phi->sim->time_to_eat);
	++phi->n_eat;
	phi->state = PHILO_STATE_SLEEPING;
	fork_drop(phi->left_fork);
	fork_drop(phi->right_fork);
	philo_lock(phi);
	phi->last_eat_ts = get_now();
	philo_unlock(phi);
}

void	philo_think(t_pphilo phi)
{
	if (phi->is_alive)
		printf("%zu %u %s\n", get_now() / TIMESTAMP_DIV,
			phi->id + 1, "is thinking");
	if (phi->sim->nphilosophers <= 100) // ?
	{
		while (phi->n_eat != 0
			&& get_now() - phi->last_eat_ts \
			< (t_u64)(phi->sim->time_to_die / 3))
			;
	}
	phi->state = PHILO_STATE_EATING;
}

void	philo_sleep(t_pphilo phi)
{
	display_state(phi, "is sleeping");
	ft_usleep(phi->sim->time_to_sleep);
	phi->state = PHILO_STATE_THINKING;
}
