/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:59:13 by MJKim             #+#    #+#             */
/*   Updated: 2023/01/28 17:04:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/minitalk_bonus.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

char	*ft_join(char *s, char c)
{
	char	*res;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		print_error("Memory allocation failed: ft_join()\n");
	len = 0;
	while (s[len])
	{
		res[len] = s[len];
		len++;
	}
	res[len] = c;
	res[len + 1] = '\0';
	free(s);
	return (res);
}

void	print_error(char *str)
{
	ft_putstr("*ERROR* ");
	ft_putstr(str);
	write(1, "\n", 1);
	exit(1);
}
