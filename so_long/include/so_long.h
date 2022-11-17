/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/17 11:52:45 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../mlx/mlx.h"
# include "./libft.h"

# define SUCCESS 0
# define FAILURE 1

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		collections;
	int		e_x;
	int		e_y;
}	t_map;

t_map	*ft_init(int argc, char **argv);

void	check_map(t_map *map);
void	find_path(t_map *map);
void	free_all(t_map *map);
void	get_map(int fd, t_map *map);
void	print_error(char *str);

#endif