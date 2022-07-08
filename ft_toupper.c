/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:34:10 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 13:43:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
int	main()
{
	printf("%c\n", ft_toupper('c'));
	printf("%c\n", ft_toupper('C'));
	printf("%c\n", ft_toupper('~'));
	printf("%c\n", ft_toupper('z'));
}
*/
