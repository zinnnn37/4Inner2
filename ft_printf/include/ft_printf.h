/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:38:01 by minjinki          #+#    #+#             */
/*   Updated: 2022/08/04 15:49:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_uitoa(unsigned int n);

int		ft_printf(const char *format, ...);

size_t	ft_printchar(int c);
size_t	ft_printstr(const char *s);
size_t	ft_printnbr(int n);
size_t	ft_numlen(unsigned int n);
size_t	ft_printunsigned(unsigned int n);
size_t	ft_printptr(unsigned long long n);
size_t	ft_printhex(unsigned int n, int x);

#endif
