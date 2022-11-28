/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:52:51 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/28 12:37:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strjoin(char *s, char c)
{
	char	*res;
	int		len;
	int		i;

	while (s[len])
		len++;
	res = (char *)malloc(sizeof(char) * (len + 2));
	i = -1;
	while (++i < len)
		res[i] = s[i];
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}
