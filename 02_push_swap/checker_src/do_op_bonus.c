/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:33:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/15 10:42:00 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

void	do_op3(t_stack *a, t_stack *b, char *s)
{
	if (ft_strcmp(s, "ra\n") == 0)
		rn(a);
	else if (ft_strcmp(s, "rb\n") == 0)
		rn(b);
	else if (ft_strcmp(s, "rr\n") == 0)
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

void	do_op2(t_stack *a, t_stack *b, char *s)
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
	else
		do_op3(a, b, s);
	//print_nodes(a, b); //
}

void	do_op(t_stack *a, t_stack *b)
{
	char	*s;

	//print_nodes(a, b); // remove
	s = get_next_line(STDIN_FILENO);
	while (s)
	{
		do_op2(a, b, s);
		free(s);
		s = get_next_line(STDIN_FILENO);
	}
	if (is_ordered_not_dup(a) == TRUE && is_empty(b) == TRUE)
		ft_putstr("OK");
	else
		ft_exit();
}
