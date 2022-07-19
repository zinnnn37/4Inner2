/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:48:54 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/19 19:15:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	new_c;
	unsigned char	*new_s;

	new_c = (unsigned char)c;
	new_s = (unsigned char *)s;
	while (*new_s != new_c)
	{
		if (*new_s == '\0')
			return (NULL);
		new_s++;
	}
	return ((char *)new_s);
}
