/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:27:02 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/11 15:02:48 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;

	if (!dst && !src)
		return (0);
	new_dst = (unsigned char *)dst;
	new_src = (unsigned char *)src;
	if (dst < src)
		while (len--)
			*new_dst = *new_src++;
	else
		while (len--)
			new_dst[len] = new_src[len];
	return (dst);
}