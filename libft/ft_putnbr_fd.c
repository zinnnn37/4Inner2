/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/11 15:16:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_putnbr_fd(int n, int fd)
{
  char  *arr;

  arr = ft_itoa(n);
  ft_putstr_fd(arr, fd);
}
