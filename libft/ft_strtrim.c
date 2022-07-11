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
	rear = ft_strlen(s1) - 1;
	while (s1[front] && ft_strchar(set, s1[front]))
		front++;
	if (front > rear)
		return (ft_strdup(""));
	while (s1[rear] && ft_strchr(set, s1[rear]))
		rear--;
	res = (char *)malloc(sizeof(char) * (rear - front + 2)); // rear - front 하면 \0 없이 딱 들어맞는 배열이 할당됨 \0 자리까지 +2
	if (!res)
		return (0);
	ft_strlcpy(res, s1 + front, rear - front + 2);
	return (res);
}
