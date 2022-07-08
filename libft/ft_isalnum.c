/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:56:04 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 15:31:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <stdio.h>
int	main()
{
	char arr[10] = "01~!=hi?";
	for (int i = 0; arr[i] != '\0'; i++)
		printf("%d\n", ft_isalnum(arr[i]));
}
*/
