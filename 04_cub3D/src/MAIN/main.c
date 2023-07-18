/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 13:03:53 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	if (ac == 2 || ac == 3)
	{
		if (ft_strcmp(av[2], "--save") != 0)
			return (print_error("Error\nInvalid argument"));
	}
	else
		return (print_error("Error\nInvalid argument"));
}
