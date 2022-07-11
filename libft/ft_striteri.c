/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/07 16:12:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void  ft_striteri(char *s, void (*f)(unsigned int, char *));
{
  size_t  i;

  i = 0;
  while (s[i])
  {
    f(i, s + i); // void라서 return 없음, char *를 매개변수로 받음! >> & 추가 or ptr 이동
    i++;
  }
}