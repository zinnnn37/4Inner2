/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:28:29 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/08 16:14:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_to_b(t_info *info, int min, int max, int mid)
{
	int	cnt;

	cnt = 0;
	if (info->a->size <= 5)
	{
		sort_small_numbers(info->a, info->b);
		return ;
	}
	while (cnt < info->len / info->chunk)
	{
		if (min <= info->a->top->rank && info->a->top->rank <= max)
		{
			cnt++;
			pn(info->a, info->b, "pb");
			if (max - min > 1 && info->b->top->rank > mid)
				rn(info->b, "rb");
		}
		rn(info->a, "ra");
	}
	min = max;
	max = max + info->len / info->chunk;
	mid = (min + max) / 2;
	if (min < info->len)
		a_to_b(info, min, max, mid);
}

void	b_to_a(t_info *info)
{
	int	top;
	int	bottom;

	top = max_from_top(info->b);
	bottom = max_from_bottom(info->b) + 1;
	//print_nodes(info->a, info->b);
	if (top <= bottom)
	{
		while (top-- > 0)
			rn(info->b, "rb");
		pn(info->b, info->a, "pa");
	}
	else
	{
		while (bottom-- > 0)
			rrn(info->b, "rrb");
		pn(info->b, info->a, "pa");
	}
}

void	sort(t_info *info)
{
	int	max;
	int	mid;

	max = info->len / info->chunk;
	mid = max / 2;
	a_to_b(info, 0, max, mid);
	while (info->b->top)
		b_to_a(info);
}
