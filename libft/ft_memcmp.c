/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:43:51 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 16:49:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	/*
	while (n-- && (*s1 || *s2))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
	*/
	unsigned char	*new_s1;
	unsigned char *new_s2;

	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (--n)
	{
		if (*new_s1 != *new_s2)
			return (*new_s1 - *new_s2);
		new_s1++;
		new_s2++;
	}
	return (*new_s1 - *new_s2); // intentionally compare only n-1 time so that the code return nth compared one
}
