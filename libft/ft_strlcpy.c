/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:42:31 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/15 19:37:10 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	size_t	srclen;
	size_t	i;

//	if (!dst || !src)
//		return (0);
	i = 0;
	srclen = ft_strlen(src);
	while (src[i] && i < destsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (destsize != 0) //destsize == 0일 때는 복사하면 x
		dst[i] = '\0';
	return (srclen);
}
