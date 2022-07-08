/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 16:12:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

/*
#include <stdio.h>
int	main()
{
	printf("hi: %zu\n", ft_strlen("hi"));
	printf("hello: %zu\n", ft_strlen("hello"));
	printf("Wanna go home!!: %zu\n", ft_strlen("Wanna go home!!"));
	printf("WORK HARD: %zu\n", ft_strlen("WORK HARD"));
}
*/
