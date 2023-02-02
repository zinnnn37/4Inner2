/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 11:04:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	print_nodes(t_stack *a, t_stack *b)
{
	t_data	*tmp;

	tmp = a->top;
	printf("\n\n\nsize: %d, %d\n\n", a->size, b->size);
	while (tmp)
	{
		printf("%d\n", tmp->data);
		tmp = tmp->next;
	}
}

void	create_and_add_node(t_stack *s, int data)
{
	t_data	*node;

	node = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!node)
		print_error();
	node->prev = NULL;
	node->data = data;
	node->next = NULL;
	if (s->size == 0)
	{
		s->top = node;
		s->bottom = node;
	}
	else
	{
		s->bottom->next = node;
		node->prev = s->bottom;
		s->bottom = node;
	}
	s->size++;
	//print_nodes(s);
}
