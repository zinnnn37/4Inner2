/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 15:19:57 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/30 15:31:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pn(t_stack from, t_stack to, char *str)
{
	if (str)
		ft_putstr(str);
	to.top.prev = from.top;
	from.top.next = to.top;
	from.top = from.top.next;
	from.top.prev = NULL;
	to.top = to.top.prev;
	to.top.next = NULL;
}

void	rrn(t_stack s, char *str)
{
	if (str)
		ft_putstr(str);
	s.bottom.next = a.top;
	s.top.prev = a.bottom;
	s.bottom = a.bottom.prev;
	s.top = a.top.prev;
	s.bottom.next = NULL;
	s.top.prev = NULL;
}

void	rrr(t_stack a, t_stack b)
{
	ft_putstr("rrr\n");
	rrn(a, NULL);
	rrn(b, NULL);
}
