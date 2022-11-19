/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:15:22 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 16:20:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	find_path(t_map *map)
{
	t_queue	*q;
	int		*pos;
	int		*res;
	
	q = init_queue(q, map->height - 2, map->width - 2);
	printf("front: %d\nrear: %d\n", q->front, q->rear);
	printf("size: %d\n", q->size);
	append(q, 1, 2);
	printf("%d, %d\n", q->data[0][0], q->data[0][1]);
	res = popleft(q);
	printf("%d, %d\n", res[0], res[1]);
/*
	pos[0] = map->p_x;
	pos[1] = map->p_y;
	pos = {map->p_x, map->p_y};
	while (pos[0] != map->e_x && pos[1] != mpa->e_y)
	{
	}*/
}
