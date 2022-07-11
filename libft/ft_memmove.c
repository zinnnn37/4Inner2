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
  unsigned char *new_d;
  unsigned char *new_s;

  if (!dst || !src)
    return (0);
  new_d = (unsigned char *)dst;
  new_s = (unsigned char *)src;
  if (dst < src)
    while (len--)
      *new_d++ = *new_s++;
  else // to preven overlap
    while (len--)
      *(new_d + len) = *(new_s + len);
  return (dst);
}

/*
만약 src의 주소가 dst보다 작은 값이라면 src와 dst의 메모리 영역이 겹칠 수 있음
> src를 dst에 처음부터 복사한다면 겹치는 부분이 src의 내용으로 변경되고,
  dst의 뒷부분이 변경된 dst의 내용으로 적용될 수 있음 ..? 글로 설명하려니 어렵네

  src: 1 2 3 4 5
  dst:       9 8 7 6 5
  복사 진행
  src: 1 2 3 4 5
  dst:       1 8 7 6 5
  src: 1 2 3 1 5 >> 메모리가 겹치니까 src도 같이 변함
  dst:       1 2 7 6 5
  src: 1 2 3 1 2
  dst:       1 2 3 6 5
  dst:       1 2 3 1 5
  dst:       1 2 3 1 2
  >> 이게 오버랩
*/