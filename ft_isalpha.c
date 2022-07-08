/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:18:10 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 15:27:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_isalpha('a'));  
	printf("%d\n", ft_isalpha('z'));  
	printf("%d\n", ft_isalpha('A'));  
	printf("%d\n", ft_isalpha('Z'));  
	printf("%d\n", ft_isalpha('~'));  
	printf("%d\n", ft_isalpha('\0'));  
	printf("%d\n", ft_isalpha(' '));  
	printf("%d\n", ft_isalpha('"'));  
}
*/
