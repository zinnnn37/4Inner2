/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:58:52 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 14:10:02 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_map	*ft_init(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		print_error("*ERROR* Check the number of input file!\n");
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		print_error("*ERROR* Check if the extension of map file is .ber!\n");
	fd = open("../maps/no_exit.ber", O_RDONLY);
	map = ft_calloc(1, sizeof(t_map *));
	get_map(fd, map);
	return (map);
}
