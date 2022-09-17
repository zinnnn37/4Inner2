/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:41:48 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/17 14:59:45 by minjinki         ###   ########.fr       */
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
	/*
	별다른 동작을 하지 않으며, 실제로 없어도 전혀 지장이 없음.
	이 명령이 필요한 이유는 호환성 대문인데,
	플랫폼에 따라서는 가변인수를 읽은 후 뒷처리를 해주어야 할 필요가 있기 때문.
	적어도 인텔 계열의 CPU에서는 아무 일도 하지 않는다고 함..
	*/
	return (cnt);
}
