/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:16:00 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/09 18:33:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	front;
	size_t	rear;

	if (!s1 || !set)
		return (0);
	front = 0;
	rear = ft_strlen(s1);
	while (s1[front])
		if (!ft_strchr(set, s1[front++]))
			break ;
	if (front == rear)
		return (ft_strdup(""));
	while (s1[--rear])
		if (!ft_strchr(set, s1[rear]))
			break ;
	res = (char *)malloc(sizeof(char) * (rear - front + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s1 + front, rear - front + 1);
	return (res);
}
