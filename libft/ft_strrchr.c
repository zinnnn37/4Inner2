/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:11 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/19 19:16:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	new_c;
	unsigned char	*new_s;

	len = ft_strlen(s);
	new_c = (unsigned char)c;
	new_s = (unsigned char *)s;
	while (new_s[len] != new_c && len > 0)
		len--;
	if (new_s[len] == new_c)
		return ((char *)(new_s + len));
	return (NULL);
}
