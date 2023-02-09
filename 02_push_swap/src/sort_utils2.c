/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:46:45 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/09 11:30:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	range_from_top(t_stack *a, int min, int max)
{
	int		cnt;
	t_data	*tmp;

	cnt = 0;
	tmp = a->top;
	while (tmp)
	{
		if (min < tmp->rank && tmp->rank <= max)
			return (cnt);
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

int	range_from_bottom(t_stack *a, int min, int max)
{
	int		cnt;
	t_data	*tmp;

	cnt = 0;
	tmp = a->bottom;
	while (tmp)
	{
		if (min < tmp->rank && tmp->rank <= max)
			return (cnt);
		cnt++;
		tmp = tmp->prev;
	}
	return (cnt);
}
