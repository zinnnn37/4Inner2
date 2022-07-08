/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:42:31 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 16:36:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t detsize)
{
	unsigned int	cnt;
	unsigned int	i;

	cnt = 0;
	i = 0;
	while (src[cnt])
	{
		if (i < size - 1)
		{
			dst[i] = src[i++];
			cnt++;
		}
		else
			cnt++;
	}
	if (size != 0)
		dst[i] = '\0';
	return (cnt);
}
