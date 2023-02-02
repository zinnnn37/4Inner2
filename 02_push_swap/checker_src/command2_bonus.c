/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:19:57 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 13:10:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"
#include <stdio.h>

void	pn2(t_stack *from, t_stack *to)
{
	to->top->prev = from->top;
	from->top = from->top->next;
	from->top->prev = NULL;
	to->top->prev->next = to->top;
	to->top = to->top->prev;
	to->top->prev = NULL;
}

void	pn(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	else if (from->size == 1 && to->size == 0)
	{
		to->top = from->top;
		to->bottom = from->top;
		from->top = NULL;
	}
	else if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = from->top;
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
		pn2(from, to);
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
