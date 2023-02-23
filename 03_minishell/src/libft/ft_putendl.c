/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:11:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/23 12:05:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putendl(const char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr(s, fd);
	ft_putchar('\n', fd);
}
