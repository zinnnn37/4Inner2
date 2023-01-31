/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 10:59:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_stack(t_stack s)
{
	s.top = NULL;
	s.bottom = NULL;
	s.size = 0;
}

int	main(int ac, char **av)
{
	struct t_stack	a;
	struct t_stack	b;

	if (ac == 1)
		print_error("Usage: ./push_swap [ args,... ]\n");
	init_stack(a);
	init_stack(b);
	get_numbers(ac, av, a);
	return (0);
}
