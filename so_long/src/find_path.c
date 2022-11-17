/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/17 13:54:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_finished(t_map *map, int *pos)
{
	return (pos[0] == map->e_x && pos[1] == map->e_y);
}
// 도착인지 확인

void	find_path(t_map *map)
{
	int	pos[2];

	pos[0] = map->p_x;
	pos[1] = map->p_y;
	while (is_finished(map, pos) == 1)
	{
	}
}
