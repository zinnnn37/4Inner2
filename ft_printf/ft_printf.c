#include "ft_printf.h"

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
	elif (c == 'c')
		cnt += ft_printchar(va_arg(ap, int)); // char로 먼저 해보기? 왜 int임
	elif (c == 's')
		cnt += ft_printstr(va_arg(ap, char *));
	elif (c == 'p')
		cnt += ft_printptr(va_arg(ap, unsigned long long)); // 주소 출력
	elif (c == 'd' || c == 'i')
		cnt += ft_printnbr(va_arg(ap, int));
	elif (c == 'u')
		cnt += ft_printunsigned(va_arg(ap, unsigned int));
	elif (c == 'x' || c == 'X')
		cnt += ft_printhex(va_arg(ap, unsigned int), c); // c에서 16진수는 리터럴 키워드(i, U, L)를 붙이지 않으면 양수취급
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
			cnt += ft_printsth(format[i]);
		i++;
	}
	va_end(ap);
	return (cnt);
}