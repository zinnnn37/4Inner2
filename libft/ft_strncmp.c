/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:43:12 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/15 18:12:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	new_s1;
	unsigned char	new_s2;

	while (n-- && (*s1 || *s2))
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
