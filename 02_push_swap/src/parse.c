/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:57:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/06 10:23:42 by minjinki         ###   ########.fr       */
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

t_bool	is_ordered(t_stack *a)
{
	t_data	*tmp;
	t_data	*check;

	tmp = a->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (FALSE);
		check = tmp->next;
		while (check)
		{
			if (tmp->data == check->data)
				return (-1);
			check = check->next;
		}
		tmp = tmp->next;
	}
	return (TRUE);
}
