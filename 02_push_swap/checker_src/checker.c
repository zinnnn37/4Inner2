/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:01:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 12:02:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

int push_swap(int ac, char **av, t_stack *a, t_stack *b)
{
	get_numbers(ac, av, a);
	do_op(a, b);
	if (is_empty(b) == FALSE)
		print_error();
	if (is_sorted(a) == FALSE)
		ft_exit();
	ft_putstr("OK\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 1)
		return (0);
	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	b.top = NULL;
	b.bottom = NULL;
	b.size = 0;
	return (push_swap(ac, av, &a, &b));
}
