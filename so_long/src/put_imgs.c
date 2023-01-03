/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_imgs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:20:05 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/03 14:21:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_img(t_map *map)
{
	put_backround(map);
	fill_map(map);
	mlx_hook(map->data->win, 17, 1L << 2, give_up, map);
	mlx_key_hook(map->data->win, key_hook, map);
}
// 1L << 2 button press mask

void	fill_map(t_map *map)
{
	map->data->y = -1;
	while (++(map->data->y) < map->height)
	{
		map->data->x = -1;
		while (++(map->data->x) < map->width)
		{
			if (map->map[map->data->y][map->data->x] == 'P')
				put_player(map);
			else if (map->map[map->data->y][map->data->x] == '1')
				put_obj(map, "./img/stump.xpm");
			else if (map->map[map->data->y][map->data->x] == 'C')
				put_obj(map, "./img/key.xpm");
			else if (map->map[map->data->y][map->data->x] == 'E')
			{
				if (map->data->collect == map->c)
					put_obj(map, "./img/opened.xpm");
				else
					put_obj(map, "./img/closed.xpm");
			}
		}
	}
}

void	put_backround(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->data->win_y)
	{
		w = 0;
		while (w < map->data->win_x)
		{
			mlx_put_image_to_window(map->data->mlx, map->data->win,
				map->img->background, w, h);
			w += IMG_W;
		}
		h += IMG_H;
	}
}

void	put_obj(t_map *map, char *path)
{
	int	img_w;
	int	img_h;

	map->img->tmp = mlx_xpm_file_to_image(map->data->mlx, path, &img_w, &img_h);
	mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->tmp,
		map->data->x * IMG_W, map->data->y * IMG_H);
}

void	put_player(t_map *map)
{
	map->p_x = map->data->x;
	map->p_y = map->data->y;
	mlx_put_image_to_window(map->data->mlx, map->data->win, map->img->front,
		map->p_x * IMG_W, map->p_y * IMG_H);
	map->map[map->p_x][map->p_y] = '0';
}
