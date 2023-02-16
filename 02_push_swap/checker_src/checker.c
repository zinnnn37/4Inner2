/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:01:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/15 11:41:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

void	init_stack(t_stack *a, t_stack *b)
{
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
	b->top = NULL;
	b->bottom = NULL;
	b->size = 0;
}

void	push_swap(int ac, char **av, t_stack *a, t_stack *b)
{
	init_stack(a, b);
	get_numbers(ac, av, a);
	if (is_ordered_not_dup(a) == DUP)
		print_error();
	do_op(a, b);
	free_nodes(a);
	free_nodes(b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac != 1)
		push_swap(ac, av, &a, &b);
	return (SUCCESS);
}
