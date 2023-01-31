/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:19:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 12:02:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **res, size_t cnt)
{
	size_t	i;

	i = 0;
	while (i < cnt)
		free(res[i++]);
	free(res);
}

static size_t	ft_count_words(const char *s)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != ' '	&& (s[i + 1] == ' ' || s[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

static void	ft_copy(char *res, const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
}

static char	**ft_malloc(char **res, const char *s, int cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			i++;
		else
		{
			j = 0;
			while (s[i + j] && s[i + j] != ' ')
				j++;
			res[cnt] = (char *)malloc(sizeof(char) * (j + 1));
			if (!res[cnt])
			{
				ft_free(res, cnt);
				return (NULL);
			}
			ft_copy(res[cnt++], s + i);
			i += j;
		}
	}
	return (res);
}

char	**ft_split(char const *s)
{
	char	**res;
	size_t	words;

	if (!s)
		return (NULL);
	words = ft_count_words(s);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = NULL;
	return (ft_malloc(res, s, 0));
}
