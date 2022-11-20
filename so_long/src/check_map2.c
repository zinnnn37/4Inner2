/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 17:56:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	bfs_init(t_bool **visited, int h, int w)
{
	visited = ft_calloc(h + 1, sizeof(t_bool *));
	if (!visited)
		print_error("*ERROR* Fail to find path!\n");
	while (i < h)
	{
		visited[i] = ft_calloc(w + 1, sizeof(t_bool));
		if (!visited[i])
			print_error("*ERROR* Fail to find path!\n");
	}
}

void	_bfs(t_bool **visited, int x, int y, int i)
{
	static int	*dx = {1, 0, -1, 0};
	static int	*dy = {0, 1, 0, -1};
	int			nx;
	int			ny;

	nx = x + dx[i];
	ny = y + dy[i];
	if ((1 < nx && nx < h - 1) || ()) // 조건확인
}

void	bfs(t_map *map, t_queue *q, int x, int y)
{
	t_bool		**visited;
	int			i;

	bfs_init(visited, map->height, map->width);
	enqueue(q, x, y);
	visited[x][y] = TRUE;
	while (q->front < q->rear)
	{
		i = 0;
		while (i < 4)
		{
			_bfs(visited, x, y, i);
		}
	}
}

void	find_path(t_map *map)
{
	t_queue	*q;
	int		*pos;
	int		*res;

	q = init_queue(q, map->height - 2, map->width - 2);
	bfs(map, q, map->p_x, map->p_y);
/*
	pos[0] = map->p_x;
	pos[1] = map->p_y;
	pos = {map->p_x, map->p_y};
	while (pos[0] != map->e_x && pos[1] != mpa->e_y)
	{
	}*/
}

/*
	printf("front: %d\nrear: %d\n", q->front, q->rear);
	printf("size: %d\n", q->size);
	enqueue(q, 1, 2);
	printf("%d, %d\n", q->data[0][0], q->data[0][1]);
	res = dequeue(q);
	printf("%d, %d\n", res[0], res[1]);
*/