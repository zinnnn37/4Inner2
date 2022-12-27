/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:42:19 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/27 18:55:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_map *map, int dir, int status)
{
	if (dir == -1 && status == 0)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->back,
			map->p_x * IMG_W, map->p_y * IMG_H);
	else if (dir == 1 && status == 0)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->front,
			map->p_x * IMG_W, map->p_y * IMG_H);
	else if (dir == -1 && status == 1)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->left,
			map->p_x * IMG_W, map->p_y * IMG_H);
	else if (dir == 1 && status == 1)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->right,
			map->p_x * IMG_W, map->p_y * IMG_H);
}

void	collect_key(t_map *map, int dir, int status)
{
	if (map->map[map->p_x][map->p_y] == 'C')
	{
		map->data->collect++;
		map->map[map->p_x][map->p_y] = '0';
		move(map, 0, status);
	}
	ft_putstr_fd("You walked ", 1);
	ft_putnbr_fd(++map->data->counter, 1);
	ft_putstr_fd(" steps\n", 1);
	move_player(map, dir, status);
}

void	move(t_map *map, int dir, int status)
{
	mlx_put_image_to_window(map->data->mlx, map->data->win,
		map->img->background, map->p_x * IMG_W, map->p_y * IMG_H);
	if (status == 0 && map->map[map->p_x][map->p_y + dir] != '1'
		&& (map->map[map->p_x][map->p_y + dir] != 'E'
		|| map->c == map->data->collect))
		map->p_y += dir;
	else if (status == 1 && map->map[map->p_x + dir][map->p_y] != '1'
		&& (map->map[map->p_x + dir][map->p_y] != 'E'
		|| map->c == map->data->collect))
		map->p_x += dir;
	else if (status == 0 && map->map[map->p_x][map->p_y + dir] != '1'
		&& (map->map[map->p_x][map->p_y + dir] == 'E'
		|| map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n", 1);
	else if (status == 1 && map->map[map->p_x + dir][map->p_y] != '1'
		&& (map->map[map->p_x + dir][map->p_y] == 'E'
		|| map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n", 1);
	//mlx_do_sync(map->data->mlx);
	printf("x: %d, y: %d\n", map->p_x, map->p_y);
	collect_key(map, dir, status);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		give_up(map);
	else if (keycode == W)
		move(map, UP, 0);
	else if (keycode == A)
		move(map, LEFT, 1);
	else if (keycode == S)
		move(map, DOWN, 0);
	else if (keycode == D)
		move(map, RIGHT, 1);
	if (map->map[map->p_x][map->p_y] == 'E')
		if (map->data->collect == map->c)
			end_game(map);
	return (0);
}
