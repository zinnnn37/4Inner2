/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:12 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/12 09:03:12 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	run(t_data *data)
{
	int	i;

	data->start_time = get_cur_time();
	i = -1;
	while (++i < data->num_philos)
		if (pthread_create(&(table->philos[i]->thread), NULL, \
			&philosopher, table->philos[i]) != 0)
			return (print_error("Fail to create thread: philo\n", data));
	if (data->num_philos > 1)
		if (pthread_create(&(data->monitor), NULL, \
			&monitoring, data) != 0)
			return (print_error("Fail to create thread: monitor\n", data));
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (print_error("Check the number of arguments\n", &data));
	if (!check_valid(ac, av, &data))
		return (print_error("Check if arguments are valid\n", &data));
	if (!init_data(&data))
		return (print_error("Fail to init data\n", &data));
	if (!run(&data))
		return (FAILURE);
	stop(&data);
	return (SUCCESS);
}