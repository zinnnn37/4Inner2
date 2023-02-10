/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/10 12:07:32 by minjinki         ###   ########.fr       */
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
	int	valid;

	init_info(info);
	get_numbers(ac, av, info->a);
	valid = is_ordered_not_dup(info->a);
	if (valid == DUP)
		print_error();
	else if (valid == TRUE)
		return (SUCCESS);
	info->len = info->a->size;
	set_rank(info->a);
	sort(info);
	//print_nodes(info->a, info->b);
	//printf("res: %d\n", is_ordered_not_dup(info->a));
	//printf("\n%d\n", info->len);
	//printf("%d\n", info->chunk);
	//free_all(info);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		ft_exit(NULL);
	return (push_swap(ac, av, &info));
}
