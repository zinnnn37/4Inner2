/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/10 14:47:27 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	print_ranks(t_stack *a) // remove
{
	t_data	*tmp;

	printf("========\n");
	tmp = a->top;
	printf("  a: %d\n--------\n", a->size);
	while (tmp)
	{
		printf("  %d\n", tmp->rank);
		tmp = tmp->next;
	}
	printf("========\n\n");
}

void	create_and_add_node(t_stack *s, int data)
{
	t_data	*node;

	node = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!node)
		print_error();
	node->prev = NULL;
	node->data = data;
	node->rank = 0;
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
	int		sorted;

	tmp = a->top;
	sorted = TRUE;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			sorted = FALSE;
		check = tmp->next;
		while (check)
		{
			if (tmp->data == check->data)
				return (DUP);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (sorted);
}

void	free_nodes(t_stack *a)
{
	t_data	*tmp;

	if (!(a->top))
		return ;
	tmp = a->top->next;
	while (tmp)
	{
		free(tmp->prev);
		if (!(tmp->next))
		{
			free(tmp);
		}
		tmp = tmp->next;
	}
}
