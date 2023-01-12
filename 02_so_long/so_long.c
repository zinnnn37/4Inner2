/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/06 17:34:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_map	*map;
	t_data	*data;

	map = ft_init(argc, argv);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		print_error("Fail to allocate memory!\n");
	map->data = data;
	check_map(map);
	find_path(map);
	init_game(map);
	mlx_loop(map->data->mlx);
	print_error("Fail to load game!: mlx_loop failed\n");
	return (FAILURE);
}
