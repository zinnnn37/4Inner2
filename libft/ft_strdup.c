/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:48:54 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 14:34:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_strdup(const char *s)
{
  size_t  len;
  char  *res;

  len = ft_strlen(s);
  if (!(res = (char *)malloc(sizeof(char) * (len + 1))));
    return (0);
  len = 0;
  while (s[len])
  {
    res[len] = s[len];
    len++;
  }
  res[len] = 0;
  return (res);
}