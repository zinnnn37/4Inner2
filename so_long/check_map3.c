/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 19:10:58 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/05 19:15:45 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	find_path2(t_map *map, t_bool **visited, t_queue *q, int *nxt)
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
