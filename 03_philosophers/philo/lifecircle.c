/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecircle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:12:06 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/11 15:29:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lifecircle(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	while (!(philo->is_dead))
	{
		if (philo->state == SLEEPING)
			sleeping(philo);
		else if (philo->state == EATING)
			eating(philo);
		else if (philo->state == THINKING)
			thinking(philo);
	}
	return (NULL);
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
	do_usleep(philo->data->ttsleep);
	philo->state = THINKING;
}

void	eating(t_philo *philo)
{
	if (philo->id % 2 == 1)
	{
		pick_fork(philo->lfork, philo);
		pick_fork(philo->rfork, philo);
	}
	else
	{
		pick_fork(philo->rfork, philo);
		if (is_one_philo(philo))
			return ;
		pick_fork(philo->lfork, philo);
	}
	display_msg(philo, EAT_MSG);
	do_usleep(philo->data->tteat);
	philo->eat_cnt++;
	philo->state = SLEEPING;
	put_fork(philo->lfork);
	put_fork(philo->rfork);
	lock_philo(philo);
	philo->last_eat = get_cur_time();
	unlock_philo(philo);
}
// 길어지면 pick, put fork랑 display는 따로 빼기

void	thinking(t_philo *philo)
{
	if (!(philo->is_dead))
		display_msg(philo, THINK_MSG);
	philo->state = EATING;
}
// 기묘한..
