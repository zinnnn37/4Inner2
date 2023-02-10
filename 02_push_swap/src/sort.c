/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:04:26 by MJKim             #+#    #+#             */
/*   Updated: 2023/02/10 09:52:30 by minjinki         ###   ########.fr       */
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
			pn(info->a, info->b, "pb");
			i++;
		}
		else if (info->a->top->rank > i && info->a->top->rank <= i + info->chunk)
		{
			pn(info->a, info->b, "pb");
			rn(info->b, "rb");
			i++;
		}
		else if (info->a->top->rank > i + info->chunk)
		{
			if (i < info->a->size / 2 && i >= 0) // ?
				rrn(info->a, "rra");
			else
				rn(info->a, "ra");
		}
	}
}

void	b_to_a(t_info *info)
{
	int	len;

	len = info->b->size;
	while (info->b->size != 0)
	{
		sort_b(info->b, len);
		pn(info->b, info->a, "pa");
		len--;
	}
}

void	sort_large_numbers(t_info *info)
{
	int	len;

	len = info->a->size;
	info->chunk = 0.000000053 * len * len + 0.03 * len + 14.5;
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
