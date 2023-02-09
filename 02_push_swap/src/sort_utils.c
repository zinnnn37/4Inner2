/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:30:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/08 16:04:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_print(t_stack *s, int i)
{
	if (i > (s->size / 2) + 1)
	{
		if (s->size == 5 && i == 3)
			ft_putstr("rra");
		ft_putstr("rra");
	}
	else
	{
		while (--i)
			ft_putstr("ra");
	}
}

void	rotate_till_min(t_stack *s)
{
	t_data	*tmp;
	int		min;
	int		i;

	tmp = s->top->next;
	min = s->top->data;
	while (tmp)
	{
		if (min > tmp->data)
			min = tmp->data;
		tmp = tmp->next;
	}
	i = 0;
	while (++i && s->top->data != min)
		rn(s, NULL);
	rotate_print(s, i);
}
