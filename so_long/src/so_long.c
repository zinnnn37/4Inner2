/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 14:57:32 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = ft_init(argc, argv);
	check_map(map);
//	mlx_things();
//	free_all();
	exit(0); // 나중에 지우기..
	return (0);
}
