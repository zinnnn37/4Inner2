/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:44:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/14 11:57:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

void	sn(t_stack *s)
{
	int	tmp;

	if (s->size <= 1)
		return ;
	tmp = s->top->data;
	s->top->data = s->top->next->data;
	s->top->next->data = tmp;
}

void	ss(t_stack *a, t_stack *b)
{
	sn(a);
	sn(b);
}

void	rn(t_stack *s)
{
	if (s->size <= 1)
		return ;
	s->bottom->next = s->top;
	s->top->prev = s->bottom;
	s->top = s->top->next;
	s->bottom = s->bottom->next;
	s->top->prev = NULL;
	s->bottom->next = NULL;
}

void	rr(t_stack *a, t_stack *b)
{
	rn(a);
	rn(b);
}
