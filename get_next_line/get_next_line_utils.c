/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:39:59 by minjinki          #+#    #+#             */
/*   Updated: 2022/08/11 15:55:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
        int     cnt;

        cnt = 0;
        while (s[cnt])
                cnt++;
        return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int	len1;
	int	len2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < len1)
		res[i] = s1[i];
	i--;
	while (i < len1 + len2 + 1)
		res[i] = s2[i - len1];
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (*(unsigned char *)s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
