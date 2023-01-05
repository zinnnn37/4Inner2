/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:28:42 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/05 12:23:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "./libft.h"

typedef struct s_queue
{
	int	**data;
	int	front;
	int	rear;
	int	size;
}	t_queue;

int		*dequeue(t_queue *q);

t_queue	*init_queue(t_queue *q, int h, int w);

void	enqueue(t_queue *q, int i, int j);
void	free_q(t_queue *q);

#endif