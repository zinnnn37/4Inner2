/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/06 13:31:16 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	print_nodes(t_stack *a, t_stack *b) // remove
{
	t_data	*tmp;

	printf("========\n");
	tmp = a->top;
	printf("  a: %d\n--------\n", a->size);
	while (tmp)
	{
		printf("  %d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("========\n\n");
	printf("========\n");
	tmp = b->top;
	printf("  b: %d\n--------\n", b->size);
	while (tmp)
	{
		printf("  %d\n", tmp->data);
		tmp = tmp->next;
	}
	printf("========\n\n");
	write(1, "cmd: ", 5);
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
}

t_bool	is_ordered_not_dup(t_stack *a)
{
	t_data	*tmp;
	t_data	*check;

	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (FALSE);
		check = tmp->next;
		while (check)
		{
			if (tmp->data == check->data)
				return (-1);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (TRUE);
}
