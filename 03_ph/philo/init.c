/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:31:04 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/12 09:31:04 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_forks(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->data->num_philos;
	if (philo->id % 2)
	{
		philo->fork[0] = (philo->id + 1) % philo->data->num_philos;
		philo->fork[1] = philo->id;
	}
}

t_philo	**init_philos(t_data *data)
{
	t_philo	**philos;
	int		i;

	philos = malloc(sizeof(t_philo *) * data->num_philos);
	if (!philos)
		return (err_null("Fail to malloc philos\n", data));
	i = -1;
	while (++i < data->num_philos)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
			return (err_null("Fail to malloc philos\n", data));
		if (pthread_mutex_init(&philos[i]->meal, NULL) != 0)
			return (err_null("Fail to init mutex\n", data));
		philos[i]->data = data;
		philos[i]->id = i;
		philos[i]->num_eat = 0;
		give_forks(philos[i]);
	}
	return (philos);
}

pthread_mutex_t	*init_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!forks)
		return (err_null("Fail to malloc mfork\n", data));
	i = -1;
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (err_null("Fail to init mutex: mfork\n", data));
	}
	return (forks);
}

t_bool	init_mutexes(t_data *data)
{
	data->mforks = init_forks(data);
	if (!(data->mforks))
		return (FALSE);
	if (pthread_mutex_init(&data->mprint, NULL) != 0)
		return (print_error("Fail to init mutex: mprint\n", data));
	if (pthread_mutex_init(&data->mdead, NULL) != 0)
		return (print_error("Fail to init mutex: mdead\n", data));
	return (TRUE);
}

t_bool	init_data(t_data *data)
{
	data->philos = init_philos(data);
	if (!(data->philos))
		return (FALSE);
	if (!init_mutexes(data))
		return (FALSE);
	data->dead = FALSE;
	return (TRUE);
}
