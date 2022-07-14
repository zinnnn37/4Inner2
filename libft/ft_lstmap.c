/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:41:31 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/12 13:26:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	head = f(ft_lstnew(lst->content));
	cur = head;
	tmp = lst->next;
	while (tmp)
	{
		cur->next = f(ft_lstnew(tmp->content));
		if (!(cur->next))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		cur = cur->next;
		tmp = tmp->next;
	}
	return (head);
}
