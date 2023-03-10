/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/07 13:35:48 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 0도 들어올 수 있나요..?
static t_bool	parsing_nums(int ac, char **av, t_data *data)
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

t_bool	init(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (print_error("Check the number of args"));
	if (!parsing_nums(ac, av, data))
		return (FALSE);
	data->
	return (TRUE);
}
