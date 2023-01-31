/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 11:49:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_and_add_node(t_stack s, int data)
{
	t_data	*node;

	node = (t_data *)ft_calloc(sizeof(t_data));
	if (!node)
		print_error();
	node.prev = NULL;
	node.data = data;
	node.next = NULL;
	if (s.size == 0)
	{
		s.top = node;
		s.bottom = node;
	}
	else
	{
		s.bottom.next = node;
		node.prev = s.bottom;
		s.bottom = node;
	}
	s.size++;
}
