#include "../include/ft_printf.h"
#include "../libft/libft.h"

size_t	ft_printnbr(int n)
{
	size_t	len;
	char	*res;

	res = ft_itoa(n);
	len = ft_strlen(res);
	ft_printstr(res);
	free(res);
	return (len);
}