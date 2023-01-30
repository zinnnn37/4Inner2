/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:44:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/30 15:24:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sn(t_stack s, char *str)
{
	int	tmp;

	if (str)
		ft_putstr(str);
	tmp = a.top.data;
	s.top.data = a.top.next.data;
	s.top.next.data = tmp;
}

void	ss(t_stack a, t_stack b)
{
	ft_putstr("ss\n");
	sn(a, NULL);
	sn(b, NULL);
}

void	rn(t_stack s, char *str)
{
	if (str)
		ft_putstr(str);
	s.bottom.next = a.top;
	s.top.prev = a.bottom;
	s.top = a.top.next;
	s.bottom = a.bottom.next;
	s.top.prev = NULL;
	s.bottom.next = NULL;
}

void	rr(t_stack a, t_stack b)
{
	ft_putstr("rr\n");
	rn(a, NULL);
	rn(b, NULL);
}
