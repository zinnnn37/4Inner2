/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:26:58 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/07 13:30:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	t_mutex	*mutex;
	int		i;
	t_philo	*philo;

	mutex = data->mutex;
	i = 0;
	while (i++ < data->nums + 3)
		pthread_mutex_destroy(mutex);
	free(data->mutex);
	while (data->philo)
	{
		philo = data->philo->next;
		free(data->philo);
		data->philo = philo;
	}
}
