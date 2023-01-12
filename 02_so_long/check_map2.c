/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/06 12:52:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**bfs_init(t_bool **visited, int h, int w)
{
	int	i;

	visited = (t_bool **)ft_calloc(h + 1, sizeof(t_bool *));
	if (!visited)
		print_error("Fail to allocate memory: fail to find path\n");
	i = 0;
	while (i < h)
	{
		visited[i] = (t_bool *)ft_calloc(w + 1, sizeof(t_bool));
		if (!visited[i++])
			print_error("Fail to allocate memory: fail to find path\n");
	}
	return (visited);
}

t_bool	bfs3(t_map *map, t_bool **visited, t_queue *q, int *nxt)
{
	if (map->map[nxt[1]][nxt[0]] != 'E')
	{
		if (map->map[nxt[1]][nxt[0]] == 'C')
			map->data->counter++;
		enqueue(q, nxt[0], nxt[1]);
	}
	else
		map->data->exit++;
	if (map->data->counter == map->c && map->data->exit == 1)
		return (TRUE);
	visited[nxt[1]][nxt[0]] = TRUE;
	return (FALSE);
}

t_bool	bfs2(t_map *map, t_bool **visited, t_queue *q, int *pos)
{
	static int	d[4] = {1, 0, -1, 0};
	int			i;
	int			nxt[2];

	i = -1;
	while (++i < 4)
	{
		nxt[0] = pos[0] + d[i];
		nxt[1] = pos[1] + d[3 - i];
		if ((0 < nxt[0] && nxt[0] < map->width - 1)
			&& (0 < nxt[1] && nxt[1] < map->height - 1)
			&& !visited[nxt[1]][nxt[0]] && map->map[nxt[1]][nxt[0]] != '1')
		{
			if (bfs3(map, visited, q, nxt))
				return (TRUE);
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
	visited[y][x] = TRUE;
	while (q->front < q->rear)
	{
		pos = dequeue(q);
		if (pos)
		{
			i = 0;
			if (bfs2(map, visited, q, pos))
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
		print_error("Path doesn't exist!\n");
	map->data->counter = 0;
	free_q(q);
}
