/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:28:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 11:45:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		print_error("*ERROR* Check the number of input file!\n");
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		print_error("*ERROR* Check if the extension of map file is .ber!\n");
	get_map();
	check_map();
	mlx_things();
	free_all();
	return (0);
}
