/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/04/11 14:42:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	leaks(void)
// {
// 	system("leaks philo");
// }

int	main(int ac, char **av)
{
	t_data	data;

	if (!init(ac, av, &data))
	{
		free_all();
		return (FAILURE);
	}
	start_simul(data);
	//free_all();
	return (SUCCESS);
}
