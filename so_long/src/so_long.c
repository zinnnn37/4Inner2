/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/17 11:14:49 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = ft_init(argc, argv);
	check_map(map);
//	for (int i = 0; map->map[i] != NULL; i++)
//		printf("%s\n", map->map[i]);
//	mlx_things();
//	free_all();
	exit(0); // 나중에 지우기..
	return (0);
}
