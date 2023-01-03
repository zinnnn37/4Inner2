/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:07:37 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/03 15:33:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
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

# define X 1
# define Y 0

# define IMG_W 50
# define IMG_H 50

typedef int	t_bool;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		collect;
	int		counter;
	int		win_x;
	int		win_y;
	int		x;
	int		y;
}	t_data;

typedef struct s_img
{
	void	*background;
	void	*front;
	void	*back;
	void	*left;
	void	*right;
	void	*closed;
	void	*opened;
	void	*key;
	void	*flower;
	void	*tmp;
}	t_img;

typedef struct s_map
{
	char	**map;
	int		height;
	int		width;
	int		p_x;
	int		p_y;
	int		c;
	int		exit;
	t_img	*img;
	t_data	*data;
}	t_map;

int		give_up(t_map *map);
int		key_hook(int key, t_map *map);

t_map	*ft_init(int argc, char **argv);

void	check_map(t_map *map);
void	end_game(t_map *map);
void	find_path(t_map *map);
void	free_all(t_map *map);
void	print_error(char *str);
void	init_game(t_map *map);
void	move_player(t_map *map, int dir, int status);
void	put_backround(t_map *map);
void	fill_map(t_map *map);
void	put_player(t_map *map);
void	put_obj(t_map *map, char *path);
void	render_img(t_map *map);
void	move(t_map *map, int dir, int status);

#endif