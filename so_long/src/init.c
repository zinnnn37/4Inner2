/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:58:52 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/25 14:40:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map(int fd, t_map *map)
{
	char	*s;
	char	*line;
	char	*tmp;

	line = NULL;
	s = get_next_line(fd);
	while (s)
	{
		if (ft_strlen(s) == 0)
			break ;
		tmp = ft_strjoin(line, s);
		if (!tmp)
			print_error("*ERROR* Fail to allocate memory!: Fail to save map!\n");
		free(line);
		line = tmp;
		free(s);
		s = get_next_line(fd);
	}
	map->map = ft_split(line, '\n');
	if (!map->map)
		print_error("*ERROR* Fail to allocate memory!: Fail to save map!\n");
	free(line);
}

t_map	*ft_init(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		print_error("*ERROR* Check the number of input file!\n");
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		print_error("*ERROR* Check if the extension of map file is .ber!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("*ERROR* No such file!\n");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		print_error("*ERROR* Fail to allocate memory!: Fail to save map\n");
	get_map(fd, map);
	close(fd);
	return (map);
}
