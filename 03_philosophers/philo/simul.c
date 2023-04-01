/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simul.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:23:24 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/01 16:44:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simul(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		pthread_create(&data->philos[i].thread, NULL,
			&lifesircle, &data->philos[i]);
}

void	thread_join(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nums)
		pthread_join(data->philos[i].thread, NULL);
}

t_bool	is_dead(t_data *data, t_philo *philo)
