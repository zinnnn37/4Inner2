/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:41:31 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/11 16:42:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	// 할당 실패 시 리스트 삭제할 때 del 사용
	t_list	*head;
	t_list	*cur;
	t_list	*tmp;

	if (!lst)
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
// strmapi랑 똑같은데 이건 연결리스트