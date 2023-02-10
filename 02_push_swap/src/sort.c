/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:04:26 by MJKim             #+#    #+#             */
/*   Updated: 2023/02/10 12:10:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_to_b(t_info *info)
{
	int	i;

	i = 0;
	while (info->a->size != 0)
	{
		if (info->a->top->rank <= i)
		{
			pn(info->a, info->b, "pb"); // pb
			i++;
		}
		else if (info->a->top->rank > i && info->a->top->rank <= i + info->chunk)
		{
			pn(info->a, info->b, "pb"); // pb
			rn(info->b, "rb"); // rb
			i++;
		}
		else if (info->a->top->rank > i + info->chunk)
		{
			if (i < info->a->size / 2 && i >= 0)
				rn(info->a, "ra"); // ra
			else
				rrn(info->a, "rra"); // rra
		}
	}
}

void	b_to_a(t_info *info)
{
	while (info->b->size != 0)
	{
		sort_b(info->b);
		pn(info->b, info->a, "pa"); // pa
	}
}

void	sort_large_numbers(t_info *info)
{
	if (info->len <= 100)
		info->chunk = 10;
	else
		info->chunk = 28;
	a_to_b(info);
	b_to_a(info);
}

void	sort(t_info *info)
{
	if (info->a->size <= 5)
		sort_small_numbers(info->a, info->b);
	else
		sort_large_numbers(info);
}
