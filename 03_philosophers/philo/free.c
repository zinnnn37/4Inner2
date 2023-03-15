/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:55:20 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/15 10:55:20 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philo(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->data->nums)	// 이거 반복문 안 해도 되나 ?!
		pthread_mutex_destroy(&philos[i].mtx);
	free(philos);
}

void	free_all(t_data *data)
{
	destroy_philo(data->philos);
}
