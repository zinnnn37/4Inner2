/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:42:19 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/20 20:10:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_key(t_map *map)
{
	map->data->collect++;
	map->map[map->p_x][map->p_y] = '0';
	mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->background,
		map->p_x * IMG_W, map->p_y * IMG_H);
}

void	move_player(t_map *map, int dir)
{
	if (dir == UP)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->back,
			map->p_x * IMG_W, map->p_y * IMG_H);
	else if (dir == DOWN)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->front,
			map->p_x * IMG_W, map->p_y * IMG_H);
	else if (dir == LEFT)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->left,
			map->p_x * IMG_W, map->p_y * IMG_H);
	else if (dir == RIGHT)
		mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->right,
			map->p_x * IMG_W, map->p_y * IMG_H);
}

void	move(t_map *map, int dir)
{
	mlx_put_image_to_window(map->mlx, map->win, map->img->background,
		map->data->win_x, map->data->win_y);
	if (dir == UP && map->map[map->p_x - 1][map->p_y] != '1'
		&& (map->map[map->p_x - 1][map->p_y] != 'E' || map->c == map->data->collect))
		map->p_x--;
	else if (dir == DOWN && map->map[map->p_x + 1][map->p_y] != '1'
		&& (map->map[map->p_x - 1][map->p_y] != 'E' || map->c == map->data->collect))
		map->p_x++;
	else if (dir == LEFT && map->map[map->p_x][map->p_y - 1] != '1'
		&& (map->map[map->p_x][map->p_y - 1] != 'E' || map->c == map->data->collect))
		map->p_y--;
	else if (dir == right && map->map[map->p_x][map->p_y + 1] != '1'
		&& (map->map[map->p_x][map->p_y + 1] != 'E' || map->c == map->data->collect))
		map->p_y++;
	else
		should_collect_all_keys(map, dir);
	//mlx_do_sync(map->data->mlx);
	ft_putstr_fd("You walked ", 1);
	ft_putnbr_fd(++map->data->counter, 1);
	ft_putstr_fd(" steps\n");
}

void	should_collect_all_keys(t_map *map, int dir)
{
	if (dir == UP && map->map[map->p_x - 1][map->p_y] != '1'
		&& (map->map[map->p_x - 1][map->p_y] != 'E' || map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n");
	else if (dir == DOWN && map->map[map->p_x + 1][map->p_y] != '1'
		&& (map->map[map->p_x - 1][map->p_y] != 'E' || map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n");
	else if (dir == LEFT && map->map[map->p_x][map->p_y - 1] != '1'
		&& (map->map[map->p_x][map->p_y - 1] != 'E' || map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n");
	else if (dir == right && map->map[map->p_x][map->p_y + 1] != '1'
		&& (map->map[map->p_x][map->p_y + 1] != 'E' || map->c != map->data->collect))
		ft_putstr_fd("You must collect all keys in the map!\n");
	if (map->map[map->p_x][map->p_y] == 'C')
		collect_key(map, dir);
	move_player(map, dir);
}

int	key_hook(int key, t_map *map)
{
	if (key == ESC)
		give_up(map);
	else if (key == W)
		move(map, UP);
	else if (key == A)
		move(map, LEFT);
	else if (key == S)
		move(map, DOWN);
	else if (key == D)
		move(map, RIGHT);
	if (map->map[map->p_x][map->p_y] == 'E')
		if (map->data->collect == map->c)
			end_game(map, 0);
	return (0);
}
