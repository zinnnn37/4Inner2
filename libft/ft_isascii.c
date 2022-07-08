/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:43:34 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 15:49:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/*
#include <stdio.h>
int	main()
{
	int	arr[5] = {-1, 0, 25, 120, 225};
	for (int i = 0; i < 5; i++)
		printf("%d\n", ft_isascii(arr[i]));
}
*/
