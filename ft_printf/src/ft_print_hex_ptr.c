/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:43:28 by minjinki          #+#    #+#             */
/*   Updated: 2022/08/04 16:47:58 by minjinki         ###   ########.fr       */
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

size_t	ft_lenptr(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (!n)
		return (0);
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

void	ft_ptr(unsigned long long n)
{
	char	*x;

	x = "0123456789abcdef";
	if (n >= 16)
	{
		ft_ptr(n / 16);
		ft_ptr(n % 16);
	}
	else
		ft_printchar(x[n]);
}

size_t	ft_printptr(unsigned long long p)
{
	size_t	len;

	len = ft_printstr("0x");
	if (p == 0)
		len += ft_printchar('0');
	else
	{
		ft_ptr(p);
		len += ft_lenptr(p);
	}
	return (len);
}
