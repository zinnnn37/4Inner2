/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:42:31 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/14 13:48:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t destsize)
{
	unsigned int	cnt;
	unsigned int	i;

	cnt = 0;
	i = 0;
	while (src[cnt])
	{
		if (i < destsize - 1)
		{
			dst[i] = src[i];
			i++;
			cnt++;
		}
		else
			cnt++;
	}
	if (destsize != 0)
		dst[i] = '\0';
	return (cnt);
}
