/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:48:45 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/19 16:20:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_data(t_map *map, t_data *data)
{
	map->data = data;
	data->mlx = mlx_init();
	if (!(data->mlx))
		print_error("*ERROR* Fail to start game!\n");
	data->win_x = map->width * IMG_W;
	data->win_y = map->height * IMG_H;
	data->win = mlx_new_window(data->mlx, data->win_x, data->win_y, "so long");
}

void	init_img(t_map *map)
{
	int	img_w;
	int	img_h;

	map->img->background = mlx_xpm_file_to_image(map->data->mlx,
			"../img/background.xpm", &img_w, &img_h);
	map->img->front = mlx_xpm_file_to_image(map->data->mlx,
			"../img/front.xpm", &img_w, &img_h);
	map->img->back = mlx_xpm_file_to_image(map->data->mlx,
			"../img/back.xpm", &img_w, &img_h);
	map->img->left = mlx_xpm_file_to_image(map->data->mlx,
			"../img/left.xpm", &img_w, &img_h);
	map->img->right = mlx_xpm_file_to_image(map->data->mlx,
			"../img/right.xpm", &img_w, &img_h);
	map->img->closed = mlx_xpm_file_to_image(map->data->mlx,
			"../img/closed.xpm", &img_w, &img_h);
	map->img->opened = mlx_xpm_file_to_image(map->data->mlx,
			"../img/opened.xpm", &img_w, &img_h);
	map->img->key = mlx_xpm_file_to_image(map->data->mlx,
			"../img/key.xpm", &img_w, &img_h);
	map->img->stump = mlx_xpm_file_to_image(map->data->mlx,
			"../img/stump.xpm", &img_w, &img_h);
}

void	init_game(t_map *map)
{
	t_img	*img;
	t_data	*data;

	img = ft_calloc(1, sizeof(t_img));
	data = ft_calloc(1, sizeof(t_data));
	if (!img || !data)
		print_error("*ERROR* Fail to allocate memory!\n");
	init_data(map, data);
	map->img = img;
	//render_img(map);
	init_img(map);
	printf("%d\n", data->win_x);
}
