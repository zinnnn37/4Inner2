/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:21:00 by MJKim             #+#    #+#             */
/*   Updated: 2023/01/26 15:21:00 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s);

char	*ft_strtrim(char const *s1)
{
	const char	set[] = {'\t', '\n', '\v', '\f', '\r', ' '};
	char	*res;
	int		front;
	int		rear;

	if (!s1 || !set)
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

int	ft_atoi(const char *str, int *res)
{
	int 	i;
	char	*trim;

	trim = ft_strtrim(str);
	if (!trim)
		print_error("Memory allocation failed!: ft_strtrim()\n");
	i = 0;
	while (trim[i])
	{
		if (trim[i] < '0' || trim[i] > '9')
			return (0);
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
	return (1);
}

