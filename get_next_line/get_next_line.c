/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:39:46 by minjinki          #+#    #+#             */
/*   Updated: 2022/08/11 15:54:52 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_save_buf(char *buf)
{
	int	i;
	int	j;
	char	*res;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (buf[i])
		res[j++] = buf[i++];
	res[j] = '\0';
	free(buf);
	return (res);
}

char	*ft_get_line(char *buf)
{
	int	i;
	char	*res;

	i = 0;
	if (!*buf)
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		res[i] = buf[i];
		i++;
	}
	if (res[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_read_line(int fd, char *before)
{
	char	*next;
	int	byte;

	if (!before)
		before = (char *)malloc(sizeof(char));
	next = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!next)
		return (NULL);
	byte = 1;
	while (byte > 0 && !ft_strchr(before, '\n'))
	{
		byte = read(fd, next, BUFFER_SIZE);
		next[byte] = '\0';
		before = ft_strjoin(before, next);
	}
	free(next);
	if (byte == -1)
		return (NULL);
	return (before);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buf = ft_read_line(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_save_buf(buf);
	return (line);
}
