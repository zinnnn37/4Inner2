/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:06:21 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/14 12:59:13 by minjinki         ###   ########.fr       */
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

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
	}
	free(matrix);
	matrix = NULL;
}
