/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:12:06 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/15 11:12:06 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	lifecircle(t_philo *philo)
{
	while (!(philo->is_dead))
	{
		if (philo->state == SLEEPING)
			sleeping(philo);
		else if (philo->state == EATING)
			eating(philo);
		else if (philo->state == THINKING)
			thinking(philo);
	}
}

t_bool	is_one_philo(t_philo *philo)
{
	if (philo->data->nums == 1)
	{
		put_fork(philo->rfork);
		while (!(philo->is_dead))
			usleep(10);
		return (TRUE);
	}
	return (FALSE);
}

void	sleeping(t_philo *philo)
{
	display_msg(philo, SLEEP_MSG);
	do_usleep(philo->data->time_to_sleep);
	philo->state = THINKING;
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pick_fork(philo->lfork);
		display_msg(philo, FORK_MSG);
		pick_fork(philo->rfork);
		display_msg(philo, FORK_MSG);
	}
	else
	{
		pick_fork(philo->rfork);
		display_msg(philo, FORK_MSG);
		if (is_one_philo(philo))
			return ;
		pick_fork(philo->lfork);
		display_msg(philo, FORK_MSG);
	}
	display_msg(philo, EAT_MSG);
	do_usleep(philo->data->time_to_eat);
	philo->eat_cnt++;
	philo->state = SLEEPING;
	put_fork(philo->lfork);
	put_fork(philo->rfork);
	lock_philo(philo);
	philo->last_eat = get_cur_time();
	unlock_philo(philo);
}

void	thinking(t_philo *philo)
{

}
