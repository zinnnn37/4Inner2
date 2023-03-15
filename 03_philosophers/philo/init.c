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

t_bool	parsing_nums(int ac, char **av, t_data *data)
{
	int	n;

	if (!ft_atoi(av[1], &data->nums) || data->nums < 1)
		return (print_error("Check if the arguments are valid: av[1]"));
	if (!ft_atoi(av[2], &n) || n < 1)
		return (print_error("Check if the arguments are valid: av[2]"));
	data->ttdie = n * 1000;
	if (!ft_atoi(av[3], &n) || n < 1)
		return (print_error("Check if the arguments are valid: av[3]"));
	data->tteat = n * 1000;
	if (!ft_atoi(av[4], &n) || n < 1)
		return (print_error("Check if the arguments are valid: av[4]"));
	data->ttsleep = n * 1000;
	if (ac == 6 && (!ft_atoi(av[5], &data->limit) || data->limit < 0))
		return (print_error("Check if the arguments are valid: av[5]"));
	else if (ac == 5 || av[5] == 0)
		data->limit = -1;
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
