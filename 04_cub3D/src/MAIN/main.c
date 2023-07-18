/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 15:21:48 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (print_error("Error\nUsage: ./cub3d file.cub [--save]\n"));
}
