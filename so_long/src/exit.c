/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:31:14 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/03 15:33:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(FAILURE);
}

/* ? */
void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->map[i]);
		map->map[i++] = NULL;
	}
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
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

void	end_game(t_map *map)
{
	mlx_destroy_window(map->data->mlx, map->data->win);
	free_map(map->map);
	// img, mlx, win free
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
