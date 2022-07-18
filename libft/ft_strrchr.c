/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:11 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/18 21:58:13 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*new_s;
	unsigned char	new_c;

	len = ft_strlen(s);
	new_s = (unsigned char *)s;
	new_c = (unsigned char)c;
	while (new_s[len] != new_c && len > 0)
		len--;
	if (new_s[len] == new_c)
		return ((char *)(new_s + len));
	return (0);
}
