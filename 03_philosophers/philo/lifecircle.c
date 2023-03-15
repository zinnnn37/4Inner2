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

void	sleeping(t_philo *philo)
{
	display_msg(philo, SLEEP_MSG);
	do_usleep(philo->data->time_to_sleep);
	philo->state = THINKING;
}

void	eating(t_philo *philo)
{

}

void	thinking(t_philo *philo)
{

}
