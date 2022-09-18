/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:23:38 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/18 14:31:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
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

char	*ft_strdup(const char *s)
{
	size_t	len;
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	char	*tmp;

	tmp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	res = tmp; // 첫 문자의 주소열 res에 저장
	while (*s1)
		*(tmp++) = *(s1++);
	while (*s2)
		*(tmp++) = *(s2++);
	*tmp = '\0';
	return (res);
}

void	lst_del_node(t_list **head, t_list *cur)
{
	t_list	*tmp;

	if (*head == cur)
		*head = cur->next;
	else
	{
		tmp = *head;
		while (tmp->next != cur)
			tmp = tmp->next;
		tmp->next = cur->next; // tmp->next = cur 에서 tmp->next = cur -> next
	}
	free(cur->content);
	// cur에서 dangling pointer처리 해주면 cur에 접근 불가 -> content도 자동적으로 접근 불가
	free(cur);
	cur = NULL;
}