#include "../include/ft_printf.h"
#include "../libft/libft.h"

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
