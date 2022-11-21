/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/21 15:43:10 by minjinki         ###   ########.fr       */
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
		matrix[i] = NULL;
	}
	free(matrix);
	matrix = NULL;
}

void	bfs_init(t_bool **visited, int h, int w)
{
	visited = ft_calloc(h + 1, sizeof(t_bool *));
	if (!visited)
		print_error("*ERROR* Fail to find path!\n");
	visited[h] = ft_calloc(w + 1, sizeof(t_bool));
	if (!visited[h])
		print_error("*ERROR* Fail to find path!\n");
}

t_bool	_bfs(t_map *map, t_bool **visited, t_queue *q, int *pos)
{
	static int	d[4] = {1, 0, -1, 0};
	int			i;
	int			nxt[2];

	i = 0;
	while (i < 4)
	{
		nxt[0] = pos[0] + d[i];
		nxt[1] = pos[1] + d[3 - i];
		if ((1 < nxt[0] && nxt[0] < map->height - 1)
			|| (1 < nxt[1] && nxt[1] < map->width - 1)
			|| visited[nxt[0]][nxt[1]] == FALSE)
		{
			if (ft_strncmp(&map->map[nxt[0]][nxt[1]], "E", 1))
				return (TRUE);
			visited[nxt[0]][nxt[1]] = TRUE;
			enqueue(q, nxt[0], nxt[1]);
		}
		free(nxt);
	}
	return (FALSE);
}

t_bool	bfs(t_map *map, t_queue *q, int x, int y)
{
	t_bool		**visited;
	int			i;
	int			*pos;

	bfs_init(visited, map->height, map->width);
	enqueue(q, x, y);
	visited[x][y] = TRUE;
	while (q->front < q->rear)
	{
		pos = dequeue(q);
		i = 0;
		if (_bfs(map, visited, q, pos) == 1)
		{
			free(pos);
			return (TRUE);
		}
		free(pos);
	}
	free_matrix(visited);
	return (FALSE);
}

void	find_path(t_map *map)
{
	t_queue	*q;
	int		*pos;
	int		*res;

	q = init_queue(q, map->height - 2, map->width - 2);
	if (!bfs(map, q, map->p_x, map->p_y))
		print_error("*ERROR* Path doesn't exist!\n");
	free_matrix(q->data);
	free(q);
	q = NULL;
}
