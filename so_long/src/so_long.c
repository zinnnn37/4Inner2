/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/15 15:24:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		print_error("*ERROR* Check the number of input file!\n");
	if (!(ft_strnstr(argv[1], ".ber")))
		print_error("*ERROR* Check if the extension of map file is .ber!\n");
	get_map();
	check_map();
	mlx_things();
	free_all();
	return (0);
}
