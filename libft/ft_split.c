/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:19:02 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/15 14:48:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (0);
}

static int	ft_countwords(char const *s, char c)
{
	int		cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		cnt++;
	}
	return (cnt);
}

static char	*ft_copy(char *res, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	if (len == 0)
		return (0);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (s);
}

static char	**ft_malloc(char **res, char *s, char c)
{
	size_t	front;
	size_t	rear;
	size_t	i;

	rear = 0;
	i = 0;
	while (s[rear] && j < ft_countwords(s, c))
	{
		while (s[rear] == c)
			rear++;
		start = rear;
		while (s[rear] && s[rear] != c)
			rear++;
		res[i] = ft_copy(s + start, rear - start);
		if (!res[i++])
			return (ft_free(res))
	}
	res[i] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (0);
	res = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!res)
		return (0);
	ft_malloc(res, (char *)s, c)
	return (res);
}
