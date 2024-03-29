/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/15 11:32:22 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

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

t_bool	is_empty(t_stack *b)
{
	if (b->size != 0)
		return (FALSE);
	return (TRUE);
}

void	free_nodes(t_stack *s)
{
	t_data	*tmp;

	if (!(s->top))
		return ;
	if (s->size == 1)
	{
		free(s->top);
		return ;
	}
	tmp = s->top->next;
	while (tmp)
	{
		free(tmp->prev);
		if (!(tmp->next))
		{
			free(tmp);
			return ;
		}
		tmp = tmp->next;
	}
}
