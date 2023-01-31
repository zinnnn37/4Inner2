/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:44:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 11:35:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sn(t_stack s, char *str)
{
	int	tmp;

	if (s.size < 2)
		return (FAILURE);
	if (str)
		ft_putstr(str);
	tmp = a.top.data;
	s.top.data = a.top.next.data;
	s.top.next.data = tmp;
	return (SUCCESS);
}

void	ss(t_stack a, t_stack b)
{
	int	a;
	int	b;

	a = sn(a, NULL);
	b = sn(b, NULL);
	if (a == SUCCESS && b == SUCCESS)
		ft_putstr("ss\n");
	else if (a == SUCCESS)
		ft_putstr("sa\n");
	else if (b == SUCCESS)
		ft_putstr("sb\n");
}

int	rn(t_stack s, char *str)
{
	if (s.size <= 1)
		return (FAILURE);
	if (str)
		ft_putstr(str);
	s.bottom.next = a.top;
	s.top.prev = a.bottom;
	s.top = a.top.next;
	s.bottom = a.bottom.next;
	s.top.prev = NULL;
	s.bottom.next = NULL;
	return (SUCCESS);
}

void	rr(t_stack a, t_stack b)
{
	int	a;
	int	b;

	a = rn(a, NULL);
	b = rn(b, NULL);
	if (a == SUCCESS && b == SUCCESS)
		ft_putstr("rr\n");
	else if (a == SUCCESS)
		ft_putstr("ra\n");
	else if (b == SUCCESS)
		ft_putstr("rb\n");
}
