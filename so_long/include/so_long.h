/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2022/12/01 12:59:13 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "./libft.h"
# include "./queue.h"
/* queue 없애고 stdio.h 여기 넣기 */
# include <fcntl.h>
# include <string.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define IMG_W 50
# define IMG_H 50

typedef int	t_bool;

typedef struct s_map
{
	void	*mlx;
	void	*win;
	char	**map;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		c;
	int		exit;
	int		count;
	int		win_x;
	int		win_y;
//	t_img	*img;
}	t_map;

typedef struct s_img
{
	void	*back;
	void	*p_left;
	void	*p_right;
	void	*door_closed;
	void	*door_opend;
	void	*key;
}	t_img;

t_map	*ft_init(int argc, char **argv);

void	check_map(t_map *map);
void	end_game(t_map *map, int status);
void	find_path(t_map *map);
void	free_all(t_map *map);
void	print_error(char *str);
//void	start_game();

#endif