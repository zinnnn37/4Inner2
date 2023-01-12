/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:10:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/06 17:33:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *s, char c)
{
	char	*res;
	int		len;
	int		i;

	if (!s)
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = c;
		res[1] = '\0';
	}
	else
	{
		len = ft_strlen(s);
		res = (char *)malloc(sizeof(char) * (len + 2));
		i = -1;
		while (++i < len)
			res[i] = s[i];
		res[i] = c;
		res[i + 1] = '\0';
		free(s);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char	*res;
	char	c;

	res = NULL;
	res = ft_join(res, '\0');
	while (read(fd, &c, 1) > 0)
	{
		res = ft_join(res, c);
		if (c == '\n')
			break ;
	}
	return (res);
}
