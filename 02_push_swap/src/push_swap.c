/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/30 16:09:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse(char	**argv)
{
	(void)argv;
}

int	main(int argc, char **argv)
{
	struct t_stack	a;
	struct t_stack	b;

	if (argc == 1)
		print_error("Usage: ./push_swap [ args,... ]\n");
	parse(argv);
	return (0);
}
