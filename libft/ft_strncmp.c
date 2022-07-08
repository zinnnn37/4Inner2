/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:43:12 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 14:53:15 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2)) // check if n == 0, while loop successfully passed
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	char s1[] = "abcdefghijk";
	char s2[] = "abcdeghijk";

	printf("%s\n%s\n\n", s1, s2);
	printf("5: %d\n", ft_strncmp(s1, s2, 5));
	printf("3: %d\n", ft_strncmp(s1, s2, 3));
	printf("7: %d\n", ft_strncmp(s1, s2, 7));
}
*/
