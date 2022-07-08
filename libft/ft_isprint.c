/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:50:25 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 15:58:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}

/*
#include <stdio.h>
int	main()
{
	char arr[10] = "aA$~Z\b \0\nd";
	for (int i = 0; i < 10; i++)
		printf("%d", ft_isprint(arr[i]));
	printf("\n1111101001\n");
}
*/
