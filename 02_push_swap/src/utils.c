/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:38:29 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 14:33:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_error(void)
{
	ft_putstr("ERROR");
	exit(FAILURE);
}

void	ft_exit(char *str)
{
	ft_putstr(str);
	exit(FAILURE);
}
