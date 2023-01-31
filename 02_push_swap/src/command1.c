/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:44:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 14:42:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sn(t_stack *s, char *str)
{
	int	tmp;

	if (s->size <= 1)
		return (FAILURE);
	if (str)
		ft_putstr(str);
	tmp = s->top->data;
	s->top->data = s->top->next->data;
	s->top->next->data = tmp;
	return (SUCCESS);
}

void	ss(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = sn(a, NULL);
	y = sn(b, NULL);
	if (x == SUCCESS && y == SUCCESS)
		ft_putstr("ss\n");
	else if (x == SUCCESS)
		ft_putstr("sa\n");
	else if (y == SUCCESS)
		ft_putstr("sb\n");
}

int	rn(t_stack *s, char *str)
{
	if (s->size <= 1)
		return (FAILURE);
	if (str)
		ft_putstr(str);
	s->bottom->next = s->top;
	s->top->prev = s->bottom;
	s->top = s->top->next;
	s->bottom = s->bottom->next;
	s->top->prev = NULL;
	s->bottom->next = NULL;
	return (SUCCESS);
}

void	rr(t_stack *a, t_stack *b)
{
	int	x;
	int	y;

	x = rn(a, NULL);
	y = rn(b, NULL);
	if (x == SUCCESS && y == SUCCESS)
		ft_putstr("rr\n");
	else if (a == SUCCESS)
		ft_putstr("ra\n");
	else if (b == SUCCESS)
		ft_putstr("rb\n");
}
