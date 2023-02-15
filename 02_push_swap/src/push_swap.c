/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/15 10:57:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
/*
void	check_leaks(void)
{
	system("leaks push_swap");
}
*/
void	init_info(t_info *info)
{
	info->a = ft_calloc(1, sizeof(t_stack));
	info->b = ft_calloc(1, sizeof(t_stack));
	info->chk_b = ft_calloc(1, sizeof(t_data));
	info->chk_t = ft_calloc(1, sizeof(t_data));
	info->len_b = 0;
	info->len_t = 0;
	info->len = 0;
	info->chunk = 0;
}

void	push_swap(int ac, char **av, t_info *info)
{
	int	valid;

	init_info(info);
	get_numbers(ac, av, info->a);
	valid = is_ordered_not_dup(info->a);
	if (valid == DUP)
		print_error();
	else if (valid == TRUE)
		return ;
	info->len = info->a->size;
	set_rank(info->a);
	sort(info);
	//print_nodes(info->a, info->b);
	free_all(info);
	//atexit(check_leaks);
	return ;
}

int	main(int ac, char **av)
{
	t_info	info;

	if (ac == 1)
		ft_exit(NULL);
	push_swap(ac, av, &info);
	return (SUCCESS);
}
