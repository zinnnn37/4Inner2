/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:53:07 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 17:15:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	hi;
	unsigned int	i;

	if (!*needle)
		return (haystack);
	hi = 0;
	while (haystack[hi])
	{
		if (haystack[hi] == needle[0])
		{
			i = 0;
			while (needle[i])
			{
				if (haystack[hi + i] != needle[i])
					break ;
				if (needle[i] == '\0' && hi + i < len)
					return (haystack + hi);
				i++;
			}
		}
		hi++;
	}
}
