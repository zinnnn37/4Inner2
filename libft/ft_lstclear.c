/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:25:57 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/11 16:38:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{/*
	t_list	*cur;
	t_list	*nxt;

	if (!lst || !del)
		return ;
	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		ft_isdelone(*cur, del);
		cur->next = NULL;
		cur = nxt;
	}
	*/
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
