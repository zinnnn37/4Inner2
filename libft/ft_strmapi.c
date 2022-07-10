/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 16:12:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  char  *res;
  size_t  i;
  size_t  len;

  len = ft_strlen(s);
  res = (char *)malloc(sizeof(char) * (len * 1));
  if (!res)
    return (0);
  i = 0;
  while (s[i])
  {
    res[i] = f(i, s[i]);
    i++;
  }
  res[len] = 0;
  return (res);
}