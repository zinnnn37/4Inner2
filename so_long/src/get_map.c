/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:51:17 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 13:56:30 by minjinki         ###   ########.fr       */
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
		free(line);
		line = tmp;
		free(s);
		s = get_next_line(fd);
	}
	map->map = ft_split(line, '\n');
	free(line);
	close(fd);
}
