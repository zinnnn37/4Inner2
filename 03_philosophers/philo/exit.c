/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:22:45 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 11:45:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_data(t_data *data)
{
	int	i;

	if (!data)
		return ;
	if (data->philos)
	{
		i = -1;
		while (++i < data->num_philos)
		{
			if (data->philos[i])
				free(data->philos[i]);
		}
		free(data->philos);
	}
	if (data->mforks)
		free(data->mforks);
	free(data);
}

int	print_error(char *s, t_data *data)
{
	free_data(data);
	printf("%s", s);
	return (FAILURE);
}

void	*err_null(char *s, t_data *data)
{
	free_data(data);
	printf("%s", s);
	return (NULL);
}
