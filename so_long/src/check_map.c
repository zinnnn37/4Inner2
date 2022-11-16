/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:56:57 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 15:38:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_elements(char *line, t_map *map)
{
	int	len;
	int	i;
}

void	check_valid(int status, char *line, t_map *map)
{
	map->height++;
	if (status == 0)
		check_wall(line, map);
	else
		check_elements(line, map);
}

void	check_map(t_map *map)
{
	int	i;

	check_valid(0, map->map[0], map);
	i = 0;
	while (map[i])
	{
		check_valid(1, map);
	}
	if (map->height < 3 && map->width < 3)
		print_error("*ERROR* Invalid Map!\n");
	check_valid(0, map->map[height - 1], map)
}
