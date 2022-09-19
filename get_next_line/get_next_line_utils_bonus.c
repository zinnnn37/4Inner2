/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:23:48 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/19 11:06:04 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	char	*tmp;

	tmp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	res = tmp; // 첫 문자의 주소열 res에 저장
	if (s1)
	{
		while (*s1)
			*(tmp++) = *(s1++);
	}
	while (*s2)
		*(tmp++) = *(s2++);
	*tmp = '\0';
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (*(unsigned char *)s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *)malloc(count * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, count * size);
	return (res);
}
