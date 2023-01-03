/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/03 15:33:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_matrix(int **matrix)
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

int	**bfs_init(t_bool **visited, int h, int w)
{
	int	i;

	visited = (t_bool **)ft_calloc(h + 1, sizeof(t_bool *));
	if (!visited)
		print_error("*ERROR* Fail to allocate memory: fail to find path\n");
	i = 0;
	while (i < h)
	{
		visited[i] = (t_bool *)ft_calloc(w + 1, sizeof(t_bool));
		if (!visited[i++])
			print_error("*ERROR* Fail to allocate memory: fail to find path\n");
	}
	return (visited);
}

t_bool	_bfs(t_map *map, t_bool **visited, t_queue *q, int *pos)
{
	static int	d[4] = {1, 0, -1, 0};
	int			i;
	int			nxt[2];

	i = -1;
	while (++i < 4)
	{
		nxt[0] = pos[0] + d[i];
		nxt[1] = pos[1] + d[3 - i];
		if ((0 < nxt[0] && nxt[0] < map->height - 1)
			&& (0 < nxt[1] && nxt[1] < map->width - 1)
			&& visited[nxt[0]][nxt[1]] == FALSE
			&& map->map[nxt[0]][nxt[1]] != '1')
		{
			if (map->map[nxt[0]][nxt[1]] == 'E' && map->c == map->data->counter)
				return (TRUE);
			if (map->map[nxt[0]][nxt[1]] == 'C')
				map->data->counter++;
			visited[nxt[0]][nxt[1]] = TRUE;
			enqueue(q, nxt[0], nxt[1]);
		}
	}
	return (FALSE);
}

t_bool	bfs(t_map *map, t_queue *q, int x, int y)
{
	t_bool		**visited;
	int			i;
	int			*pos;

	visited = NULL;
	visited = bfs_init(visited, map->height, map->width);
	enqueue(q, x, y);
	visited[x][y] = TRUE;
	while (q->front < q->rear)
	{
		pos = dequeue(q);
		if (pos)
		{
			i = 0;
			if (_bfs(map, visited, q, pos) == TRUE)
			{
				free(pos);
				free_matrix(visited);
				return (TRUE);
			}
			free(pos);
		}
	}
	free_matrix(visited);
	return (FALSE);
}

void	find_path(t_map *map)
{
	t_queue	*q;

	q = NULL;
	q = init_queue(q, map->height - 2, map->width - 2);
	if (!bfs(map, q, map->p_x, map->p_y))
		print_error("*ERROR* Path doesn't exist!\n");
	map->data->counter = 0;
	free_q(q);
}

/*
	bfs가 아니라 dfs로 ㅉ야함
	floodfill 알고리즘
	재귀로 4방향을 다 돌면서 코인도 ++ 하면서
	E에 도달하는지, 코인을 다 모을 수 있는지 확인해야 함
*/