/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/13 16:57:52 by minjinki         ###   ########.fr       */
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
	//free_all();
	return (SUCCESS);
}
