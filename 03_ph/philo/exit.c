/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:22:45 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 11:09:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->philos)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			if (data->philos[i])
				free(data->philos[i]);
			i++;
		}
		free(data->philos);
	}
	if (data->mforks)
		free(data->mforks);
}

int	print_error(char *s, t_data *data)
{
	free_data(data);
	printf("%s", str);
	return (FAILURE);
}

void	*err_null(char *s, t_data *data)
{
	free_data(data);
	printf("%s", str);
	return (NULL);
}
