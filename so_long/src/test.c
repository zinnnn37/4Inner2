/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:32:29 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/16 13:50:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*s;
	char	*line;
	char	*tmp;
	char	**map;

	fd = open("../maps/no_exit.ber", O_RDONLY);
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
	map = ft_split(line, '\n');
	free(line);
	close(fd);
	return (0);
}
