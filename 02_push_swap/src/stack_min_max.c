/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:59:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/08 13:06:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_data	*find_not_ranked(t_stack *s)
{
	t_data	*tmp;

	tmp = s->top;
	while (tmp)
	{
		if (tmp->rank == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_data	*min(t_stack *s)
{
	t_data	*min;
	t_data	*tmp;

	tmp = find_not_ranked(s);
	if (!tmp)
		return (NULL);
	min = tmp;
	while (tmp)
	{
		if (tmp->data < min->data && tmp->rank == 0)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
