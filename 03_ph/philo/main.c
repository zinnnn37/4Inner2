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

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (print_error("Check the number of arguments\n", &data));
	if (!check_valid(ac, av, &data))
		return (print_error("Check if arguments are valid\n", &data));
	if (!init_data(&data))
		return (print_error("Fail to init data\n", &data));
	return (SUCCESS);
}