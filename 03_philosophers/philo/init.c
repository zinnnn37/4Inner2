/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/04/11 14:38:27 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	parsing_nums(int ac, char **av, t_data *data)
{
	if (!ft_atoi(av[1], &data->nums) || data->nums < 1)
		return (print_error("Check if the arguments are valid: av[1]"));
	if (!ft_atoi(av[2], &data->ttdie) || data->ttdie < 0)
		return (print_error("Check if the arguments are valid: av[2]"));
	if (!ft_atoi(av[3], &data->tteat) || data->tteat < 0)
		return (print_error("Check if the arguments are valid: av[3]"));
	if (!ft_atoi(av[4], &data->ttsleep) || data->ttsleep < 0)
		return (print_error("Check if the arguments are valid: av[4]"));
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
		return (FALSE);	// print_error in init_forks()
	data->start_time = get_cur_time();
	create_philo(data);
	start_simul(data);
	return (TRUE);
}
