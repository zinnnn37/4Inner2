/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/06 11:52:31 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (is_ordered(a) == -1)
		print_error();
	else if (is_ordered(a) == TRUE)
		return (SUCCESS);
	sort_small_numbers(a, b);
	print_nodes(a, b);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		ft_exit("Usage: ./push_swap [ args,... ]");
	return (push_swap(ac, av, &a, &b));
}
