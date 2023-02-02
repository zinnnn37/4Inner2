/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 11:05:02 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack s)
{
	s.top = NULL;
	s.bottom = NULL;
	s.size = 0;
}

void	push_swap(int ac, char **av, t_stack *a, t_stack *b)
{
	get_numbers(ac, av, a);
	sort_small_numbers(a, b);
	print_nodes(a, b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		ft_exit("Usage: ./push_swap [ args,... ]");
	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;
	push_swap(ac, av, &a, &b);
	return (0);
}
