/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:36:11 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 14:41:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len--) // check if len == 0, while loop sucessfully ends
	{
		if (s[len] == c)
			return ((char *)(s + len));
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	char str[] = "afbcdefghfijk";
	char* p = ft_strrchr(str, 'a');

	if (p != NULL)
	{
		printf("word to find: %c\n", *p);
		printf("substring   : %s\n", p);
	}
}
*/
