/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:39:46 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/28 16:27:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buf, char *next)
{
	char	*res;

	res = ft_strjoin(buf, next);
	free(buf);
	return (res);
}

char	*ft_read_file(int fd, char *buf)
{
	char	*tmp;
	size_t	byte;

	if (!buf)
		buf = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = '\0';
		buf = ft_join(buf, tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(tmp);
	return (buf);
}

char	*ft_get_line(char *buf)
{
	char	*res;
	int		i;

	if (!*buf)
	{
		free(buf;)
		return (NULL);
	}
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (buf[++i] && buf[i] != '\n')
		res[i] = buf[i];
	if (buf[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*ft_next_line(char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(buf) - i, sizeof(char));
	j = 0;
	while (buf[++i])
		res[j++] = buf[i];
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_read_file(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	if (!line)
		return (NULL);
	buf = ft_next_line(buf);
	return (line);
}
