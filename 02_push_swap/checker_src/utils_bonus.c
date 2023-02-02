/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:06:21 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/02 12:02:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_include/checker.h"

void	print_error(void)
{
	ft_putstr("ERROR");
	exit(FAILURE);
}

void	ft_exit(void)
{
	ft_putstr("KO");
	exit(FAILURE);
}
