/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/08 11:26:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "./mlx/mlx.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_map
{
	char			*line;
	struct t_map	*next;
}	t_map;

typedef struct s_data
{
	int				height;
	int				width;
	int				player;
	int				coin;
	int				exit;
	struct t_map	*start;
	struct t_map	*end;
}	t_data;

void	check_map(int fd, t_data *map);
void	print_error(int status);

#endif