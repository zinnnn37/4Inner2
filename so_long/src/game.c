/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:48:45 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/01 13:01:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_map *map)
{
	map->win_x = map->width * IMG_W;
	map->win_y = map->height * IMG_H;
}

void	start_game(t_map *map)
{
	init_game(map);
}
