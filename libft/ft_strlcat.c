/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:04:48 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/09 18:33:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
		size_t destsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (destsize <= dst_len)
		return (destsize + src_len);
	while (src[i] && i < destsize - dst_len - 1)
		dst[dst_len + i] = src[i++];
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
