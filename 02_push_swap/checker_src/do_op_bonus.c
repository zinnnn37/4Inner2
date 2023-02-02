/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:33:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 13:13:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"
#include <stdio.h> // remove

void	do_op2(t_stack *a, t_stack *b, char *s)
{
	if (ft_strcmp(s, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(s, "rra\n") == 0)
		rrn(a);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rrn(b);
	else if (ft_strcmp(s, "rrr\n") == 0)
		rrr(a, b);
	else
		print_error();
}

void	do_op(t_stack *a, t_stack *b)
{
	char	*s;

	print_nodes(a, b); // remove
	s = get_next_line(1);
	while (s)
	{
		if (ft_strcmp(s, "sa\n") == 0)
			sn(a);
		else if (ft_strcmp(s, "sb\n") == 0)
			sn(b);
		else if (ft_strcmp(s, "ss\n") == 0)
			ss(a, b);
		else if (ft_strcmp(s, "pa\n") == 0)
			pn(b, a);
		else if (ft_strcmp(s, "pb\n") == 0)
			pn(a, b);
		else if (ft_strcmp(s, "ra\n") == 0)
			rn(a);
		else if (ft_strcmp(s, "rb\n") == 0)
			rn(b);
		else
			do_op2(a, b, s);
		print_nodes(a, b);
		free(s);
		s = get_next_line(1);
	}
}
