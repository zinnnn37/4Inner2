/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 18:23:38 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/17 17:34:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strlen(char *s)
{
	int	len;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

// strdup
// strjoin
// strchr

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
		tmp = cur->next;
	}
	free(cur->content);
	free(cur);
	cur = NULL;
}