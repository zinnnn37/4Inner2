#ifndef CHECK_H
#define CHECK_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int putstr(char *s)
{
	int len = -1;
	if (!s)
		s = "(null)";
	while (s[++len])
		write(1, &s[len], 1);
	return len;
}

int putnbr(int nb)
{
	long long n = nb;
	int	len = 0;

	if (n < 0)
	{
		n *= -1;
		len += write(1, "-", 1);
	}
	if (n > 9)
	{
		len += putnbr(n / 10);
		len += putnbr(n % 10);
	}
	else
		len += write(1, n + '0', 1);
	return (len);
}

int puthex(unsigned int nb)
{
	int len = 0;

	if (nb > 15)
	{
		len += puthex(nb / 16);
		len += puthex(nb % 16);
	}
	else
		len += write(1, &"0123456789abcdef"[nb], 1);
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list ap;
	int	i = -1;
	int	len = 0;

	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] != '%')
			len += write(1, &format[i], 1);
		else if (format[i] == '%' && format[i+1])
		{
			i++;
			if (format[i] == 's')
				len += putstr(va_arg(ap, char *));
			else if (format[i] == 'd')
				len += putnbr(va_arg(ap, int));
			else if (format[i] == 'x')
				len += puthex(va_arg(ap, unsigned int));
		}
	}
	va_end(ap);
	return (len);
}

#endif