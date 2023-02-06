/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:01:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/06 13:30:09 by minjinki         ###   ########.fr       */
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

int	push_swap(int ac, char **av, t_stack *a, t_stack *b)
{
	init_stack(a, b);
	get_numbers(ac, av, a);
	if (is_ordered_not_dup(a) == -1)
		print_error();
	else if (is_ordered_not_dup(a) == TRUE)
		return (SUCCESS);
	if (is_empty(b) == FALSE)
		print_error();
	do_op(a, b);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (0);
	return (push_swap(ac, av, &a, &b));
}
