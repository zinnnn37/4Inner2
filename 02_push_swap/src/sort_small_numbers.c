/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:56:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/10 14:36:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->data > a->bottom->data)
		sn(a, "sa");
}

void	sort_three(t_stack *a)
{
	int	tmp[3];

	tmp[0] = a->top->data;
	tmp[1] = a->top->next->data;
	tmp[2] = a->bottom->data;
	if (tmp[0] < tmp[1] && tmp[0] < tmp[2] && tmp[1] > tmp[2])
	{
		rrn(a, "rra");
		sn(a, "sa");
	}
	else if (tmp[0] > tmp[1] && tmp[0] < tmp[2] && tmp[1] < tmp[2])
		sn(a, "sa");
	else if (tmp[0] < tmp[1] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
		rrn(a, "rra");
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] < tmp[2])
		rn(a, "ra");
	else if (tmp[0] > tmp[1] && tmp[0] > tmp[2] && tmp[1] > tmp[2])
	{
		rn(a, "ra");
		sn(a, "sa");
	}
}

void	sort_four(t_stack *a, t_stack *b)
{
	rotate_till_min(a);
	pn(a, b, "pb");
	sort_three(a);
	pn(b, a, "pa");
}

void	sort_five(t_stack *a, t_stack *b)
{
	rotate_till_min(a);
	pn(a, b, "pb");
	sort_four(a, b);
	pn(b, a, "pa");
}

void	sort_small_numbers(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size == 4)
		sort_four(a, b);
	else if (a->size == 5)
		sort_five(a, b);
}
