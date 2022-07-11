/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:40:33 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 15:12:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*
#include <stdio.h>
int	main()
{
	char	arr[10] = "a2c4e6";
	for (int i = 0; arr[i] != '\0'; i++)
		printf("%d\n", ft_isdigit(arr[i]));
}
*/
