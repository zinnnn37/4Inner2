/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/15 15:24:39 by minjinki         ###   ########.fr       */
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
# include "./libft.h"

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

void	print_error(char *str);

#endif