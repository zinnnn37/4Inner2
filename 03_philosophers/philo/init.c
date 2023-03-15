/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/13 16:59:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 0도 들어올 수 있나요..?
t_bool	parsing_nums(int ac, char **av, t_data *data)
{
	if (!ft_atoi(av[1], &data->nums) || data->nums < 1)
		return (print_error("Check if the arguments are valid: av[1]"));
	if (!ft_atoi(av[2], &data->ttdie) || data->ttdie < 1)
		return (print_error("Check if the arguments are valid: av[2]"));
	if (!ft_atoi(av[3], &data->tteat) || data->tteat < 1)
		return (print_error("Check if the arguments are valid: av[3]"));
	if (!ft_atoi(av[4], &data->ttsleep) || data->ttsleep < 1)
		return (print_error("Check if the arguments are valid: av[4]"));
	if (ac == 6 && (!ft_atoi(av[5], &data->limit) || data->limit < 1))
		return (print_error("Check if the arguments are valid: av[5]"));
	else if (ac == 5)
		data->limit = -1;
	return (TRUE);
}

t_bool	init_forks(t_data *data)
{
	int	i;

	data->forks = calloc(data->nums, sizeof(t_fork));
	if (!(data->forks))
		return (print_error("Fail to allocate memory: data->forks"));
	i = -1;
	while (++i < data->nums)
	{
		if (pthread_mutex_init(&data->forks[i].mtx, NULL))
			return (print_error("Fail to initialize mutex: data->forks.mtx"));
	}
	return (TRUE);
}

t_bool	init(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (print_error("Check the number of args"));
	if (!parsing_nums(ac, av, data))
		return (FALSE);
	data->philos = calloc(data->nums, sizeof(t_philo));
	if (!(data->philos))
		return (print_error("Fail to allocate memory: data->philos"));
	if (!init_forks(data))
		return (FALSE);
	philo_create(data);
	return (TRUE);
}
