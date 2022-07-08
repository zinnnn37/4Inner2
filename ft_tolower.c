/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:42:07 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 13:45:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>
int	main()
{
	printf("%c\n", ft_tolower('c'));
	printf("%c\n", ft_tolower('C'));
	printf("%c\n", ft_tolower('~'));
	printf("%c\n", ft_tolower('Z'));
}
*/
