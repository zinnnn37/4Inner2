/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:55:20 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/11 15:29:59 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philo(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->nums)
		pthread_mutex_destroy(philos[i].mtx);
	free(philos);
}

void	free_all(t_data *data)
{
	destroy_philo(data->philos);
	free(data->forks);	// 얘는 destroy 안해도 되나 ?!
}
