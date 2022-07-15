/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:51 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/15 18:21:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	new_s1;
	unsigned char	new_s2;

	while (n--)
	{
		new_s1 = *(unsigned char *)s1;
		new_s2 = *(unsigned char *)s2;
		if (new_s1 != new_s2)
			return (new_s1 - new_s2);
		s1++;
		s2++;
	}
	return (0);
}
