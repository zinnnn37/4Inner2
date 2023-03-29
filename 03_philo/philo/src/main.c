/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:08:45 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/29 09:08:45 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	int		i;
	int		av_nums[5];
	t_data	data;

	if (ac < 5 || ac > 6)
		return (print_error("Check the number of arguments"));
	i = 0;
	while (++i < ac)
	{
		av_nums[i - 1] = philo_atoi(av[i]);
		if ((i == 1 && av_nums[i - 1] == 0) || av_nums[i - 1] == ERROR)
			return (print_error("Check if arguments are valid"));
	}
	if (!init_data(&data, ac, av_nums))
		return (print_error("Fail to initialize data"));
	if (!run_thread(&data))
		return (print_error("Fail to run thread"));
	if (pthread_mutex_lock(&(data.mmain)) == SUCCESS)
		if (pthread_mutex_unlock(&(data.mmain)) == SUCCESS)
			destroy_mutex(&data);
	return (SUCCESS);
}
