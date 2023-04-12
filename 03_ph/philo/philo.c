/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:32:43 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/12 10:32:43 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_n_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->forks[philo->fork[0]]));
	msg(philo, "has taken a fork");
	pthread_mutex_lock(&(philo->table->forks[philo->fork[1]]));
	msg(philo, "has taken a fork");
	msg(philo, "is eating");
	pthread_mutex_lock(&(philo->meal));
	philo->last_eat = get_cur_time();
	pthread_mutex_unlock(&(philo->meal));
	do_usleep(philo->data, philo->data->tteat);
	if (!is_simul_stopped(philo->data))
	{
		pthread_mutex_lock(&(philo->meal));
		philo->num_eat++;
		pthread_mutex_unlock(&(philo->meal));
	}
	msg(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->table->forks[philo->fork[1]]));
	pthread_mutex_unlock(&(philo->table->forks[philo->fork[0]]));
	do_usleep(philo->data, philo->data->ttsleep)
}

void	thinking(t_philo *philo, int print)
{
	time_t	ttthink;

	pthread_mutex_lock(&(philo->meal));
	ttthink = philo->data->ttdie - (get_cur_time() - philo->last_eat) \
		- philo->data->tteat;
	pthread_mutex_unlock(&(philo->meal));
	if (ttthink < 0)
		ttthink = 0;
	if (ttthink > 500)
		ttthink = 500;
	if (print)
		msg(philo, "is thinking");
	do_usleep(philo->data, ttthink);
}

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(&(philo->table->forks[philo->fork[0]]));
	msg(philo, "has taken a fork");
	do_usleep(philo->data, philo->data->ttdie);
	msg(philo, "is dead");
	pthread_mutex_unlock(&(philo->table->forks[philo->fork[0]]));
}

void	*philosopher(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->must_eat == 0)
		return (NULL);
	pthread_mutex_lock(&(philo->meal));
	philo->last_eat = philo->data->start_time;
	pthread_mutex_unlock(&(philo->meal));
	//run_delay(&(philo->data->start_time));
	//if (philo->data->ttdie == 0)
	//	return (NULL);
	if (philo->data->num_philos == 1)
		return (one_philo(philo));
	else if (philo->id % 2)
		thinking(philo, FALSE);
	while (!is_simul_stopped(philo->data))
	{
		eating_n_sleeping(philo);
		thinking(philo, TRUE);
	}
	return (NULL);
}
