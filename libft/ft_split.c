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

static void	ft_free(char **s, size_t i)
{
	while (i--)
		free(s[i]);
	free(s);
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

static void	ft_copy(char *res, char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
}

static void	ft_malloc(char **res, char *s, char c)
{
	size_t	word;
	size_t	i;
	size_t	j;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = 0;
			while (s[i + j] && s[i + j] != c)
				j++;
			res[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[word])
			{
				ft_free(res, word - 1);
				return ;
			}
			ft_copy(res[word++], s + i, c);
			i += j;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (0);
	words = ft_countwords(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res[words] = 0;
	ft_malloc(res, (char *)s, c);
	return (res);
}
