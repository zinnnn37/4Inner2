/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:42:19 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/01 13:16:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	move_player(t_map *map, int status, int dir)
{
}

void	key_hook(int key, t_map *map)
{
	if (key == ESC)
		end_game(map, 1);
	else if (key == W)
		move_player(map, 'status', UP);
	else if (key == A)
		move_player(map, 'status', LEFT);
	else if (key == S)
		move_player(map, 'status', DOWN);
	else if (key == D)
		move_player(map, 'status', RIGHT);
	if (map->map[map->p_x][map->p_y] == 'E')
		end_game(map, 0);
}
