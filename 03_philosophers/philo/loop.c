/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:54:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/07 15:14:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosophers(t_data *data)
{
	t_philo	*philo;

	philo = data->philo;
	while (philo)
	{
		philo->begin = get_time();
		printf("%zu\n", philo->begin);
		pthread_create(&(philo->philo_id), NULL, &pros, philo);
		philo = philo->next;
	}
	// check if died
	
	return (TRUE);
}
