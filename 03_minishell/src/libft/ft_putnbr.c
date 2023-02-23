/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:15:33 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/23 12:04:52 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putnbr(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', fd);
	}
	if (n < 10)
	{
		ft_putchar(n + '0', fd);
		return ;
	}
	ft_putnbr(n / 10, fd);
	ft_putchar(n % 10 + '0', fd);
}
