/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:01:00 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 16:19:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

t_queue	*init_queue(t_queue *q, int h, int w)
{
	q = ft_calloc(1, sizeof(t_queue));
	q->data = ft_calloc(h * w, sizeof(int *));
	q->size = h * w;
	return (q);
}

void	append(t_queue *q, int i, int j)
{
	q->data[q->rear] = ft_calloc(3, sizeof(int));
	q->data[q->rear][0] = i;
	q->data[q->rear][1] = j;
	q->rear = (q->rear + 1) % q->size;
}

int	*popleft(t_queue *q)
{
	int	*res;

	res = ft_calloc(3, sizeof(int));
	res[0] = q->data[q->front][0];
	res[1] = q->data[q->front][1];
	q->front = (q->front + 1) % q->size;
	return (res);
}
