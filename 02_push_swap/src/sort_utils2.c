/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:19:13 by MJKim             #+#    #+#             */
/*   Updated: 2023/02/10 14:35:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_b(t_stack *b)
{
	int		i;
	t_data	*tmp;

	i = 0;
	tmp = b->top;
	while (tmp->rank && tmp->rank != b->size && ++i < b->size)
		tmp = tmp->next;
	if (i < b->size / 2)
	{
		while (i > 0)
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
