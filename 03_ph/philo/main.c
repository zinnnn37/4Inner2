/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:12 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 15:17:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	run(t_data *data)
{
	int	i;

	data->start_time = get_cur_time();
	i = -1;
	while (++i < data->num_philos)
		if (pthread_create(&(data->philos[i]->thread), NULL, \
			&philosopher, data->philos[i]) != 0)
			return (print_error("Fail to create thread: philo\n", data));
	if (data->num_philos > 1)
		if (pthread_create(&(data->monitor), NULL, \
			&monitoring, data) != 0)
			return (print_error("Fail to create thread: monitor\n", data));
	return (TRUE);
}

void	stop(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i]->thread, NULL);
	if (data->num_philos > 1)
		pthread_join(data->monitor, NULL);
	destroy_mutexes(data);
	free_data(data);
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (ac != 5 && ac != 6)
		return (print_error("Check the number of arguments\n", data));
	if (check_valid(ac, av, data))
		return (FAILURE);
	if (!init_data(data))
		return (print_error("Fail to init data\n", data));
	if (!run(data))
		return (FAILURE);
	stop(data);
	return (SUCCESS);
}
