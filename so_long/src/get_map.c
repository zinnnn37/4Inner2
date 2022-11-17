/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:51:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/17 13:07:37 by minjinki         ###   ########.fr       */
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
			print_error("*ERROR* Fail to save map!\n");
		free(line);
		line = tmp;
		free(s);
		s = get_next_line(fd);
	}
	map->map = ft_split(line, '\n');
	if (!map->map)
		print_error("*ERROR* Fail to save map!\n");
	free(line);
}
