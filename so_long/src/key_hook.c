/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:42:19 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/20 15:40:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_map *map, int status, int dir)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img->background,
		)
}

int	key_hook(int key, t_map *map)
{
	if (key == ESC)
		give_up(map);
	else if (key == W)
		move_player(map, UP);
	else if (key == A)
		move_player(map, LEFT);
	else if (key == S)
		move_player(map, DOWN);
	else if (key == D)
		move_player(map, RIGHT);
	if (map->map[map->p_x][map->p_y] == 'E')
		end_game(map, 0);
	return (0);
}
