/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:01:00 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 17:49:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_queue	*init_queue(t_queue *q, int h, int w)
{
	q = ft_calloc(1, sizeof(t_queue));
	if (!q)
		print_error("*ERROR* Fail to find path!\n");
	q->data = ft_calloc(h * w, sizeof(int *));
	if (!(q->data))
		print_error("*ERROR* Fail to find path!\n");
	q->size = h * w;
	return (q);
}

void	enqueue(t_queue *q, int i, int j)
{
	q->data[q->rear] = ft_calloc(3, sizeof(int));
	if (!(q->data[q->rear]))
		print_error("*ERROR* Fail to find path!\n");
	q->data[q->rear][0] = i;
	q->data[q->rear][1] = j;
	q->rear = (q->rear + 1) % q->size;
}

int	*dequeue(t_queue *q)
{
	int	*res;

	res = ft_calloc(3, sizeof(int));
	if (!res)
		print_error("*ERROR* Fail to find path!\n");
	res[0] = q->data[q->front][0];
	res[1] = q->data[q->front][1];
	free(q->data[q->front])
	q->data[q->front] = NULL;
	q->front = (q->front + 1) % q->size;
	return (res);
}
