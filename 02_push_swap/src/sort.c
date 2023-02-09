/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_home.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:04:26 by MJKim             #+#    #+#             */
/*   Updated: 2023/02/09 23:04:26 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	a_to_b(t_info *info, int i)
{
	int	len;

	len = info->a->size - 1;
	while (info->a->size != 0)
	{
		if (info->a->top->rank <= i)
		{
			pn(a, b, "pb");
			i++;
		}
		else if (info->a->top->rank > i && info->a->top->rank <= i + info->chunk)
		{
			pn(a, b, "pb");
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
