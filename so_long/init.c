/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:58:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/05 15:59:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(int fd, t_map *map)
{
	char	*s;
	char	*line;
	char	*tmp;

	line = ft_strdup("");
	s = get_next_line(fd);
	while (s)
	{
		if (ft_strlen(s) == 0)
			break ;
		tmp = ft_strjoin(line, s);
		if (!tmp)
			print_error("Fail to allocate memory!: Fail to save map!\n");
		free(line);
		free(s);
		line = tmp;
		s = get_next_line(fd);
	}
	if (ft_strlen(line) == 0)
		print_error("Empty map file!\n");
	free(s);
	map->map = ft_split(line);
	if (!map->map)
		print_error("Fail to allocate memory!: Fail to save map!\n");
	free(line);
}

t_map	*ft_init(int argc, char **argv)
{
	t_map	*map;
	int		fd;

	if (argc != 2)
		print_error("Check the number of input file!\n");
	if ((ft_strlen(argv[1]) > 4
			&& ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber") != 0)
		|| ft_strlen(argv[1]) <= 4)
		print_error("Check if the extension of map file is .ber!\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("No such file!\n");
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		print_error("Fail to allocate memory!: Fail to save map\n");
	get_map(fd, map);
	if (!map->map[0])
		print_error("Empty map file!\n");
	close(fd);
	return (map);
}
