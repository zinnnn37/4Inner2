/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:32:29 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/19 16:38:15 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	test(int map[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			map[i][j] = 1;
}

int	main(int argc, char **argv)
{
	int	map[10][10] = { 0, };

	test(map);
	printf("%d\n", map[0][0]);
}
