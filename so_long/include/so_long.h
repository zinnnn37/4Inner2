/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/25 14:25:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft.h"
# include "./queue.h"
# include <fcntl.h>
# include <string.h>
# include "../mlx/mlx.h"

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef int	t_bool;

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
void	print_error(char *str);
void	start_game();

#endif