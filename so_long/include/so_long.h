/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 13:53:23 by minjinki         ###   ########.fr       */
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
	int		coin;
	int		e_x;
	int		e_y;
}	t_map;

void	get_map(t_map map);
void	print_error(char *str);

#endif