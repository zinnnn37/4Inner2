/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_nbr_un.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:44:07 by minjinki          #+#    #+#             */
/*   Updated: 2022/08/08 15:07:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

size_t	ft_printstr(const char *s)
{
	size_t	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

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

size_t	ft_numlen(unsigned int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	size_t	len;

	len = ft_numlen(n);
	res = (char *)calloc(sizeof(char), len + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--len] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

size_t	ft_printunsigned(unsigned int n)
{
	size_t	len;
	char	*res;

	res = ft_uitoa(n);
	len = ft_strlen(res);
	ft_printstr(res);
	free(res);
	return (len);
}
