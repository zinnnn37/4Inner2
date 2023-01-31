/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:56:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 14:59:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->data > a->bottom->data)
		sn(a, "sa\n");
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

void	sort_four(void)
{
}

void	sort_five(void)
{
}

void	sort_small_numbers(t_stack *a, t_stack *b)
{
	(void)b;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
}
