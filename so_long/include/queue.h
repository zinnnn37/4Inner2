/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:28:42 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 16:15:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "./libft.h"
# include <stdio.h>

typedef struct s_queue
{
	int	**data;
	int	front;
	int	rear;
	int	size;
}	t_queue;

int		*popleft(t_queue *q);

t_queue	*init_queue(t_queue *q, int h, int w);

void	append(t_queue *q, int i, int j);

#endif