/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:19:57 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 12:01:10 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

void	pn(t_stack *from, t_stack *to) // segfault
{
	if (from->size == 0)
		return ;
	if (to->size == 0)
	{
		to->top = from->top;
		from->top = from->top->next;
		to->top->next = NULL;
		from->top->prev = NULL;
	}
	else if (from->size == 1)
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = from->top;
		from->top = NULL;
	}
	else
	{
		to->top->prev = from->top;
		write(1, "1\n", 2);
		from->top->next = to->top;
		write(1, "2\n", 2);
		from->top = from->top->next;
		write(1, "3\n", 2);
		from->top->prev = NULL;
		write(1, "4\n", 2);
		to->top = to->top->prev;
		write(1, "5\n", 2);
		to->top->next = NULL;
		write(1, "6\n", 2);
	}
	from->size--;
	to->size++;
}

void	rrn(t_stack *s)
{
	if (s->size <= 1)
		return ;
	s->bottom->next = s->top;
	s->top->prev = s->bottom;
	s->bottom = s->bottom->prev;
	s->top = s->top->prev;
	s->bottom->next = NULL;
	s->top->prev = NULL;
}

void	rrr(t_stack *a, t_stack *b)
{
	rrn(a);
	rrn(b);
}
