/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 14:54:44 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 15:14:41 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
//	while (n--)
//		*(char *)s++ = 0;
	ft_memset(s, 0, n);
}

/*
#include <stdio.h>
int main()
{
	int n[] = { 1, 1,1,1,1,1,1,1,1,1};

	for (int i = 0; i < 10; i++)
		printf("%d ", n[i]);
	printf("\n");
	ft_bzero(n, 7);
	for (int i = 0; i < 10; i++)
		printf("%d ", n[i]);

	char s[] = "abcdefghij";
	printf("\n\n%s\n", s);
	ft_bzero(s, 7);
	for (int i = 0; i < 10; i++)
		printf("%c", s[i]);
}
*/
