/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:39:46 by minjinki          #+#    #+#             */
/*   Updated: 2022/08/04 15:23:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_join(char *buf, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		line = ft_substr(buf, 0, i+1);
		tmp = ft_substr(buf, i+1, ft_strlen(buf)-i);
		free(buf);
		buf = tmp;
		if (*buf == '\0')
		{
			free(buf);
			buf = 0; // dangling > 없이 해보기..
		}
	}
	else
	{
		line = ft_substr(buf, 0, ft_strlen(buf));
		free(buf);
		buf = 0;
	}
	return (line);
}

char	*ft_get_line(char *buf, char *line, int byte)
{
	if (byte <= 0 && buf == NULL)
		return (NULL);
	else
		return (ft_join(buf, line));
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	char		*tmp;
	char		*join_tmp;
	int			byte;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	byte = read(fd, tmp, BUFFER_SIZE);
	while (byte > 0)
	{
		if (!buf)
			buf = ft_calloc(1, sizeof(char));
		tmp[byte] = '\0';
		join_tmp = ft_strjoin(buf, tmp);
		buf = join_tmp;
		free(join_tmp);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break;
		byte = read(fd, tmp, BUFFER_SIZE);
	}
	return (ft_get_line(buf, line, byte));
}