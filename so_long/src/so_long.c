/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/19 18:35:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// void	print_map(t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map->height)
// 		printf("%s\n", map->map[i++]);
// 	printf("\nheight: %d\nwidth: %d\n", map->height, map->width);
// 	printf("p_x: %d\np_y: %d\n", map->p_x, map->p_y);
// 	printf("collections: %d\n", map->collections);
// 	printf("exit: %d\n", map->exit);
// }

int	main(int argc, char **argv)
{
	t_map	*map;

	map = ft_init(argc, argv);
	check_map(map);
	find_path(map);
	init_game(map);
	mlx_loop(map->data->mlx);
//	end_game(map, 0); > loop 때문에 안 나옴 ..
	print_error("*ERROR* Fail to load game!: mlx_loop failed\n");
	return (FAILURE);
}
