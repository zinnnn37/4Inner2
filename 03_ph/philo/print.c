/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:59:49 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 11:09:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(t_philo *philo, char *s)
{
	pthread_mutex_lock(&(philo->data->mprint));
	if (is_simul_stopped(philo->data))
	{
		pthread_mutex_unlock(&(philo->data->mprint));
		return ;
	}
	printf("%ld\t%d\t%s\n", get_cur_time() - philo->data->start_time, \
		philo->id + 1, s);
	pthread_mutex_unlock(&(philo->data->mprint));
}
