/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:19:57 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 12:49:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pn2(t_stack *from, t_stack *to)
{
	if (from->size == 1)
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = from->top;
		from->top = NULL;
	}
	else
	{
		to->top->prev = from->top;
		from->top = from->top->next;
		from->top->prev = NULL;
		to->top->prev->next = to->top;
		to->top = to->top->prev;
		to->top->prev = NULL;
	}
}

void	pn(t_stack *from, t_stack *to, char *str)
{
	if (from->size == 0)
		return ;
	else if (from->size == 1 && to->size == 0)
	{
		to->top = from->top;
		from->top = NULL;
	}
	else if (to->size == 0)
	{
		to->top = from->top;
		from->top = from->top->next;
		to->top->next = NULL;
		from->top->prev = NULL;
	}
	else
		pn2(from, to);
	ft_putstr(str);
	from->size--;
	to->size++;
}

int	rrn(t_stack *s, char *str)
{
	if (s->size <= 1)
		return (FAILURE);
	if (str)
		ft_putstr(str);
	s->bottom->next = s->top;
	s->top->prev = s->bottom;
	s->bottom = s->bottom->prev;
	s->top = s->top->prev;
	s->bottom->next = NULL;
	s->top->prev = NULL;
	return (SUCCESS);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = rrn(a, NULL);
	y = rrn(b, NULL);
	if (x == SUCCESS && y == SUCCESS)
		ft_putstr("rrr\n");
	else if (x == SUCCESS)
		ft_putstr("rra\n");
	else if (y == SUCCESS)
		ft_putstr("rrb\n");
}
