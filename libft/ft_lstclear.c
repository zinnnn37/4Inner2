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
{
	t_list	*cur;
	t_list	*nxt;

	cur = *lst;
	while (cur)
	{
		nxt = cur->next;
		ft_isdelone(*cur);
		cur->next = NULL;
		cur = nxt;
	}
}
