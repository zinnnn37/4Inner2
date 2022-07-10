/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:23:55 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 13:31:32 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long ft_convert(int n)
{
  long  new_n;

  if (n == 0)
    return (ft_strdup("0"));
  else if (n < 0)
    new_n = -(long)n;
  else
    new_n = (long)n;
  
  return (new_n);
}

static size_t ft_count_digit(int n)
{
  size_t  cnt;

  cnt = 0;
  while (n)
  {
    n /= 10;
    cnt++;
  }
  return (cnt);
}

char  *ft_itoa(int n)
{
  char  *res;
  long  new_n;
  size_t  len;

  new_n = ft_convert(n);
  len = ft_count_digit(n);
  if (n < 0)
    len++;
  res = (char *)malloc(sizeof(char) * (len + 1));
  if (!res)
    return (0);
  res[len] = 0;
  while (--len >= 0)
  {
    res[len] = new_n % 10 + '0';
    new_n /= 10;
  }
  if (n < 0)
    res[len] = '-';
  return (res);
}