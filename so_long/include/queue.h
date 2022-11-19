/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 13:28:42 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 13:38:50 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdio.h>

typedef struct s_queue
{
	int	**data;
	int	front;
	int	rear;
}	t_queue;

void	init_queue(t_queue *q, int h, int w);

#endif