/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:36:43 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/20 11:57:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (!c)
		return (((char *)str + i));
	while (*str)
	{
		if (*str == (unsigned char)c)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1, size_t len)
{
	char	*res;
	size_t	i;

	if (!s1)
		return (NULL);
	i = 0;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	char	*temp;

	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	result = temp;
	while (*s1)
		*(temp++) = *(s1++);
	while (*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	return (result);
}

void	ft_lstdel(t_list **head, t_list *cur)
{
	t_list	*tmp;

	if (*head == cur)
		*head = cur->next;
	else
	{
		tmp = *head;
		while (tmp->next != cur)
			tmp = tmp->next;
		tmp->next = cur->next;
	}
	free(cur->content);
	free(cur);
	cur = NULL;
}
