/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:28:39 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 17:32:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
  void  *res;

  res = (void *)malloc(count * size);
  if (res == 0)
    return (0);
  ft_memset(res, 0, count * size);
  return (res);
}
