/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:43:28 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/15 12:09:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_len_of_hex(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	ft_printhex(unsigned int n, int c)
{
	char	*small;
	char	*cap;

	small = "0123456789abcdef";
	cap = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_printhex(n / 16, c);
		ft_printhex(n % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_printchar(small[n]);
		else
			ft_printchar(cap[n]);
	}
	return (ft_len_of_hex(n));
}