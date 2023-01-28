/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:21:00 by MJKim             #+#    #+#             */
/*   Updated: 2023/01/28 13:52:16 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	while (i < srclen && i + 1 < destsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (destsize != 0)
		dst[i] = '\0';
	return (srclen);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*(unsigned char *)s != (unsigned char)c)
	{
		if (*(unsigned char *)s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strdup(const char *s)
{
	int		len;
	char	*res;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	return (res);
}

char	*ft_strtrim(char const *s1)
{
	const char	set[] = {'\t', '\n', '\v', '\f', '\r', ' '};
	char		*res;
	int			front;
	int			rear;

	if (!s1)
		return (NULL);
	front = 0;
	rear = ft_strlen(s1) - 1;
	while (s1[front] && ft_strchr(set, s1[front]))
		front++;
	if (front > rear || rear == -1)
		return (ft_strdup(""));
	while (s1[rear] && ft_strchr(set, s1[rear]))
		rear--;
	res = (char *)malloc(sizeof(char) * (rear - front + 2));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1 + front, rear - front + 2);
	return (res);
}

int	ft_atoi(char *str, int *res)
{
	int		i;
	char	*trim;
	int		status;

	trim = ft_strtrim(str);
	status = 1;
	if (!trim)
		print_error("Memory allocation failed!: ft_strtrim()\n");
	i = 0;
	while (trim[i])
	{
		if (trim[i] < '0' || trim[i] > '9')
			status = 0;
		i++;
	}
	i = 0;
	*res = 0;
	while ('0' <= trim[i] && trim[i] <= '9')
	{
		*res *= 10;
		*res += trim[i] - '0';
		i++;
	}
	free(trim);
	return (status);
}
