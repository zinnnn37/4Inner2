/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:48:45 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/05 15:59:32 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_data(t_map *map, t_data *data)
{
	data->mlx = mlx_init();
	if (!(data->mlx))
		print_error("Fail to start game!\n");
	data->win_x = map->width * IMG_W;
	data->win_y = map->height * IMG_H;
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "so long");
}

void	init_img(t_map *map)
{
	int	img_w;
	int	img_h;

	map->img->background = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/background.xpm", &img_w, &img_h);
	map->img->front = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/front.xpm", &img_w, &img_h);
	map->img->back = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/back.xpm", &img_w, &img_h);
	map->img->left = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/left.xpm", &img_w, &img_h);
	map->img->right = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/right.xpm", &img_w, &img_h);
	map->img->closed = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/closed.xpm", &img_w, &img_h);
	map->img->opened = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/opened.xpm", &img_w, &img_h);
	map->img->key = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/key.xpm", &img_w, &img_h);
	map->img->flower = mlx_xpm_file_to_image(map->data->mlx,
			"./textures/flower.xpm", &img_w, &img_h);
}

void	init_game(t_map *map)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		print_error("Fail to allocate memory!\n");
	init_data(map, map->data);
	map->img = img;
	init_img(map);
	render_img(map);
}
