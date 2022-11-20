/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/20 17:05:37 by minjinki         ###   ########.fr       */
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

t_bool	_bfs(t_map *map, t_bool **visited, t_queue *q, int *cur)
{
	if ((1 < cur[0] && cur[0] < map->height - 1)
		|| (1 < cur[1] && cur[1] < map->width - 1)
		|| visited[cur[0]][cur[1]] == FALSE)
	{
		if (ft_strncmp(&map->map[cur[0]][cur[1]], "E", 1))
			return (TRUE);
		visited[cur[0]][cur[1]] = TRUE;
		enqueue(q, cur[0], cur[1]);
	}
	return (FALSE);
}

t_bool	bfs(t_map *map, t_queue *q, int x, int y)
{
	static int	dx[4] = {1, 0, -1, 0};
	static int	dy[4] = {0, 1, 0, -1};
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
		while (i < 4)
		{
			if (_bfs(map, visited, q, [pos[0] + dx[i], pos[2] + dy[i]]) == 1)
			{
				free(pos);
				return (TRUE);
			}
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

/*
	pos[0] = map->p_x;
	pos[1] = map->p_y;
	pos = {map->p_x, map->p_y};
	while (pos[0] != map->e_x && pos[1] != mpa->e_y)
	{
	}*/
/*
	printf("front: %d\nrear: %d\n", q->front, q->rear);
	printf("size: %d\n", q->size);
	enqueue(q, 1, 2);
	printf("%d, %d\n", q->data[0][0], q->data[0][1]);
	res = dequeue(q);
	printf("%d, %d\n", res[0], res[1]);
*/