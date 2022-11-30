/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:31:14 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/30 13:41:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_error(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
		write(2, &str[i++], 1);
	exit(FAILURE);
}

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

void	end_game(t_map *map, int status)
{
	//mlx_destroy_window(map->mlx, map->win);
	free_map(map->map);
	// img, mlx, win free
	free(map);
	map = NULL;
	if (status == 0)
	{
		ft_putstr_fd("Congratulations! You suceed!\n", 1);
		exit(SUCCESS);
	}
	else
		print_error("You failed...\n");
}
