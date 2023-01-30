/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:23:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/30 12:26:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_node(t_stack stack, data)
{
	t_data	*node;

	node = (t_data *)ft_calloc(sizeof(t_data));
	node.data = data;
	node.prev = stack.bottom;
	stack.bottom = node;
	node.next = NULL;
}