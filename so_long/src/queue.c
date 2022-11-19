/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:01:00 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 13:39:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

void	init_queue(t_queue *q, int h, int w)
{
	q = ft_calloc(1, sizeof(t_queue));
	q->data = ft_calloc(h * w + 1, sizeof(int *));
	for (int i = 0; i < h * w + 1; i++)
		printf("%p ", q->data[i]);
}
