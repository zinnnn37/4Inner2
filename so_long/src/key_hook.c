/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:42:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/04 10:17:52 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	open_chest(t_map *map)
{
	int	w;
	int	h;

	h = -1;
	while (++h < map->height)
	{
		w = -1;
		while (++w < map->width)
		{
			if (map->map[h][w] == 'E')
			{
				mlx_put_image_to_window(map->data->mlx, map->data->win,
					map->img->background, w * IMG_W, h * IMG_H);
				mlx_put_image_to_window(map->data->mlx, map->data->win,
					map->img->opened, w * IMG_W, h * IMG_H);
			}
		}
	}
}

void	move_player(t_map *map, int dir, int status)
{
	mlx_put_image_to_window(map->data->mlx, map->data->win,
		map->img->background, map->data->x * IMG_W, map->data->y * IMG_H);
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
	if (map->map[map->p_y][map->p_x] == 'C')
	{
		map->data->collect++;
		if (map->c == map->data->collect)
			open_chest(map);
		map->map[map->p_y][map->p_x] = '0'; // 바꿔야 한번 더 갈 때 collect 값 그대로
		mlx_put_image_to_window(map->data->mlx, map->data->win,
			map->img->background, map->p_x * IMG_W, map->p_y * IMG_H); // 열쇠 가리기
	}
	move_player(map, dir, status);
	ft_putstr_fd("You walked ", 1);
	ft_putnbr_fd(++map->data->counter, 1);
	ft_putstr_fd(" steps\n", 1);
}

void	move(t_map *map, int dir, int status)
{
	map->data->x = map->p_x;
	map->data->y = map->p_y;
	if (status == Y && map->map[map->p_y + dir][map->p_x] != '1'
		&& (map->map[map->p_y + dir][map->p_x] != 'E'
		|| map->c == map->data->collect))
	{
		map->p_y += dir;
		collect_key(map, dir, status);
	}
	else if (status == X && map->map[map->p_y][map->p_x + dir] != '1'
		&& (map->map[map->p_y][map->p_x + dir] != 'E'
		|| map->c == map->data->collect))
	{
		map->p_x += dir;
		collect_key(map, dir, status);
	}
	else if (status == Y && map->map[map->p_y + dir][map->p_x] != '1'
		&& (map->map[map->p_y + dir][map->p_x] == 'E'
		|| map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n", 1);
	else if (status == X && map->map[map->p_y][map->p_x + dir] != '1'
		&& (map->map[map->p_y][map->p_x + dir] == 'E'
		|| map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n", 1);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		give_up(map);
	else if (keycode == W)
		move(map, UP, Y);
	else if (keycode == A)
		move(map, LEFT, X);
	else if (keycode == S)
		move(map, DOWN, Y);
	else if (keycode == D)
		move(map, RIGHT, X);
	if (map->map[map->p_y][map->p_x] == 'E')
		if (map->data->collect == map->c)
			end_game(map);
	return (0);
}
