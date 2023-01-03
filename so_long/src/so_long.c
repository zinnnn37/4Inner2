/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/03 14:45:40 by minjinki         ###   ########.fr       */
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
	t_data	*data;

	map = ft_init(argc, argv);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		print_error("*ERROR* Fail to allocate memory!\n");
	map->data = data;
	check_map(map);
	find_path(map);
	init_game(map);
	mlx_loop(map->data->mlx);
	print_error("*ERROR* Fail to load game!: mlx_loop failed\n");
	return (FAILURE);
}
