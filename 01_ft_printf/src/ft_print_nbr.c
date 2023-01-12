/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 12:11:49 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/16 13:42:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

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
