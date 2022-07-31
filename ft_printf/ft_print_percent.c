#include "ft_printf.h"

size_t	ft_printstr(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

