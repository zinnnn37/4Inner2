/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:16:51 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 17:27:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	atoi(const char *str)
{
	int	minus;
	int	ans;

	minus = 1;
	ans = 0;
	while (*str)
		if (!(9 <= *str && *str++ <= 13))
			break ;
	while (*str)
	{
		if (*str == '-')
			minus *= -1;
		if (!(*str == '+' || *str++ == '-'))
			break ;
	}
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			ans = ans * 10 + (*str - '0');
		str++;
	}
	return (minus * ans);
}
