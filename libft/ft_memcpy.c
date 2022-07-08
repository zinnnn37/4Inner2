/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:16:03 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 15:32:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	int	i;

	i = 0;
	while (n--)
	{
		*(char *)(dst + i) = *(char *)(src + i);
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
int main()
{
	char	dst[] = "zzzzzzzzzz";
	char	src[] = "abcdefghij";

	ft_memcpy(dst, src, 5);
	printf("%s\n", dst);

	int	dsti[] = {};
	int srci[] = {1,2,3,4,5,6,7,8,9,10};

	ft_memcpy(dsti, srci, 10 * sizeof(int));
	for (int i = 0; i < 10; i++)
		printf("%d ", dsti[i]);

	return 0;
}
*/
