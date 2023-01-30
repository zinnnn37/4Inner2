/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/30 12:13:15 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse(char	**argv, int	**nums)
{
	
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack b;

	if (argc == 1)
		print_error("Usage: ./push_swap [ args,... ]\n");
	parse(argv, &nums);
	return (0);
}
