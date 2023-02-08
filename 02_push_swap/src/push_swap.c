/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/08 16:07:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_info(t_info *info)
{
	info->a = ft_calloc(1, sizeof(t_stack));
	info->b = ft_calloc(1, sizeof(t_stack));
	info->len = 0;
	info->chunk = 0;
}

int	push_swap(int ac, char **av, t_info *info)
{
	init_info(info);
	get_numbers(ac, av, info->a);
	if (is_ordered_not_dup(info->a) == -1)
		print_error();
	else if (is_ordered_not_dup(info->a) == TRUE)
		return (SUCCESS);
	info->len = info->a->size;
	set_rank(info->a);
	if (info->len <= 5)
		sort_small_numbers(info->a, info->b);
	else
	{
		if (info->len <= 100)
			info->chunk = 5;
		else
			info->chunk = 8; // 해보고 고치기                             
		sort(info);
	}
	//print_nodes(info->a, info->b);
	//printf("\n%d\n", info->len);
	//printf("%d\n", info->chunk);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		ft_exit("Usage: ./push_swap [ args,... ]");
	return (push_swap(ac, av, &info));
}
