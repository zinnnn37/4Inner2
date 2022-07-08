/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:48:54 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 14:34:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char str[] = "abcdefghijk";
	char* p = ft_strchr(str, 'f');
	char* p2 = ft_strchr(str, 'c');

	if (p != NULL)
	{
		printf("word to find: %c\n", *p);
		printf("substring   : %s\n", p);
	}
	if (p2 != NULL)
	{
		printf("word to find: %c\n", *p2);
		printf("substring   : %s\n", p2);
	}
}
*/
