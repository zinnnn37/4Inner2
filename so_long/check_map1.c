/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:56:57 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/05 19:26:52 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(char *line, t_map *map)
{
	map->width = ft_strlen(line);
	if (map->width < 3)
		print_error("Invalid map!: size too small\n");
	while (*line)
	{
		if (*line == ' ')
			print_error("Invalid map!: should be rectangular\n");
		if (*line != '1')
			print_error("Invalid map!: should be surrounded by wall\n");
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
			print_error("Invalid map!: should have only one player\n");
		map->p_y = map->height - 1;
		map->p_x = i;
	}
	else if (c == 'E')
	{
		if (map->e_x != 0 || map->e_y != 0)
			print_error("Invalid map!: should have only one exit\n");
		map->e_y = map->height - 1;
		map->e_x = i;
	}
	else if (c == 'C')
		map->c++;
	else
		print_error("Invalid map!: should have 1, 0, P, E, C only\n");
}

void	check_elements(char *line, t_map *map)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (len != map->width)
		print_error("Invalid map!: map should be rectangular\n");
	if (line[0] == ' ' || line[map->width - 1] == ' ')
		print_error("Invalid map!: map should be rectangular\n");
	if (line[0] != '1' || line[map->width - 1] != '1')
		print_error("Invalid map!: should be surrounded by wall\n");
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
	if (map->height < 3)
		print_error("Invalid map!: size too small\n");
	if (map->p_x == 0 || map->p_y == 0)
		print_error("Invalid map!: check the player\n");
	if (map->e_x == 0 || map->e_y == 0)
		print_error("Invalid map!: check the exit\n");
	if (map->c == 0)
		print_error("Invalid map!: at least one collectible\n");
	check_valid(0, map->map[map->height - 1], map);
	map->height--;
}
