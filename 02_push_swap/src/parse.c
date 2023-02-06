/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:57:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/06 10:04:04 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_numbers(int ac, char **av, t_stack *s)
{
	int		i;
	int		j;
	int		data;
	char	**res;

	i = 0;
	while (++i < ac)
	{
		res = ft_split(av[i]);
		if (!res || !*res)
			print_error();
		j = -1;
		while (res[++j])
		{
			if (ft_atoi(res[j], &data) == FALSE)
				print_error();
			create_and_add_node(s, data);
		}
	}
}
