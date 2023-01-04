/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:31:14 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/04 11:46:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(FAILURE);
}

void	free_map(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i++] = NULL;
	}
	free(matrix);
	matrix = NULL;
}

void	destroy_img(t_map *map)
{
	mlx_destroy_image(map->data->mlx, map->img->background);
	mlx_destroy_image(map->data->mlx, map->img->flower);
	mlx_destroy_image(map->data->mlx, map->img->key);
	mlx_destroy_image(map->data->mlx, map->img->back);
	mlx_destroy_image(map->data->mlx, map->img->front);
	mlx_destroy_image(map->data->mlx, map->img->left);
	mlx_destroy_image(map->data->mlx, map->img->right);
	mlx_destroy_image(map->data->mlx, map->img->closed);
	mlx_destroy_image(map->data->mlx, map->img->opened);
	free(map->img);
}

void	end_game(t_map *map)
{
	destroy_img(map);
	mlx_destroy_window(map->data->mlx, map->data->win);
	free_map(map->map);
	free(map);
	map = NULL;
	ft_putstr_fd("========== YOU WIN! ==========\n", 1);
	exit(SUCCESS);
}

int	give_up(t_map *map)
{
	mlx_destroy_window(map->data->mlx, map->data->win);
	ft_putstr_fd("========== YOU LOSE ==========\n", 2);
	exit(FAILURE);
}
