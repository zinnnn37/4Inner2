/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:41:48 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/16 13:43:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

size_t	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_deal_percent(char c, va_list ap)
{
	size_t	cnt;

	cnt = 0;
	if (c == '%')
		cnt += ft_printchar('%');
	else if (c == 'c')
		cnt += ft_printchar(va_arg(ap, int));
	else if (c == 's')
		cnt += ft_printstr(va_arg(ap, char *));
	else if (c == 'p')
		cnt += ft_printptr(va_arg(ap, unsigned long long));
	else if (c == 'd' || c == 'i')
		cnt += ft_printnbr(va_arg(ap, int));
	else if (c == 'u')
		cnt += ft_printunsigned(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		cnt += ft_printhex(va_arg(ap, unsigned int), c);
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	size_t	cnt;

	va_start(ap, format);
	i = 0;
	cnt = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			cnt += ft_deal_percent(format[i + 1], ap);
			i++;
		}
		else
			cnt += ft_printchar(format[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}
