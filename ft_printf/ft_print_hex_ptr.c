#include "ft_printf.h"

size_t	ft_len_of_hex(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		len++;
	}
	return (len);
}

size_t	ft_printhex(unsigned int n, char c)
{
	char	*x;
	char	*X;

	x = "0123456789abcdef";
	X = "0123456789ABCDEF";
	if (n >= 16)
	{
		ft_printhex(n / 16);
		ft_printhex(n % 16);
	}
	else
	{
		if (c == 'x')
			ft_printchar(x[n]); // error시 putchar_fd로 변경
		else
			ft_printchar(X[n]);
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

	len = ft_putstr("0x");
	if (!ptr)
		len += ft_putchar('0');
	else
	{
		ft_ptr(n);
		len += ft_lenptr(n);
	}
	return (len);
}