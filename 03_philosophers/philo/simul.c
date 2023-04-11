/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:24 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/11 15:27:48 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simul(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		pthread_create(&data->philos[i].thread, NULL,
			&lifecircle, &data->philos[i]);
}

void	thread_join(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		pthread_join(data->philos[i].thread, NULL);
}

void	destroy_things(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		pthread_mutex_destroy(data->philos[i].mtx);
	free(data->philos);
}
