/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:56:57 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/25 14:55:49 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_wall(char *line, t_map *map)
{
	map->width = ft_strlen(line);
	if (map->width < 3)
		print_error("*ERROR* Invalid map!1\n");
	while (*line)
	{
		if (*line != '1')
			print_error("*ERROR* Invalid map!2\n");
		line++;
	}
}

void	_check_elements(t_map *map, char c, int i)
{
	if (c == '0' || c == '1')
		return ;
	else if (c == 'P')
	{
		if (map->p_x != 0 || map->p_y != 0)
			print_error("*ERROR* Invalid map!4\n");
		map->p_x = map->height - 1;
		map->p_y = i;
	}
	else if (c == 'E')
	{
		if (map->e_x != 0 || map->e_y != 0)
			print_error("*ERROR* Invalid map!5\n");
		map->e_x = map->height - 1;
		map->e_y = i;
	}
	else if (c == 'C')
		map->collections++;
	else
		print_error("*ERROR* Invalid map!6\n");
}

void	check_elements(char *line, t_map *map)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (len != map->width || line[0] != '1' || line[map->width - 1] != '1')
		print_error("*ERROR* Invalid map!3\n");
	i = -1;
	while (++i < len)
		_check_elements(map, line[i], i);
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
	while (map->map[++i])
		check_valid(1, map->map[i], map);
	if (map->p_x == 0 || map->p_y == 0 || map->e_x == 0 || map->e_y == 0)
		print_error("*ERROR* Invalid map!7\n");
	check_valid(0, map->map[map->height - 1], map);
	map->height--;
}