/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:19:13 by MJKim             #+#    #+#             */
/*   Updated: 2023/02/09 23:19:13 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_b(t_stack *b, int len)
{
	int		i;
	t_data	*tmp;

	i = -1;
	tmp = b->top;
	while (++i < b->size && tmp->rank != len)
		tmp = tmp->next;
	if (i < b->size / 2)
	{
		while (i >= 0)
		{
			rn(b, "rb");
			i--;
		}
	}
	else
	{
		while (i < b->size)
		{
			rrn(b, "rrb");
			i++;
		}

	}
}
