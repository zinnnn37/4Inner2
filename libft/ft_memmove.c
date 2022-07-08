/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:27:02 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 15:27:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dst, const void *src, size_t len)
{
  unsigned char temp[len];

  if (!dst && !src)
    return (0);
  ft_memcpy(temp, src, len);
  ft_memcpy(dst, temp, len);
  return (dst);
}
