/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/30 12:05:04 by minjinki         ###   ########.fr       */
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
//	start_game(map);
	free_all(map);
	return (0);
}
