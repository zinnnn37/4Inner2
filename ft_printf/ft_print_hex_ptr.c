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

size_t	ft_printptr(unsigned long long p)
{

}