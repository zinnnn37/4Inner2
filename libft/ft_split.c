/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:23:55 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/08 13:31:32 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void **ft_free(char **s, size_t i)
{
  while (i--)
    free(s[i]);
  free(s);
}

static size_t ft_countwords(char *s, char c)
{
  size_t  cnt;

  cnt = 0;
  while (*s)
  {
    while (*s && *s == c)
      s++;
    while (*s && *s != c)
      s++;
    cnt++;
  }
  return (cnt);
}

static  void  ft_copy(char *res, char *s, char c)
{
  size_t  i;

  i = 0;
  while (*s != c)
  {
    res[i] = s[i];
    i++;
  }
  res[i] = 0;
}

static void ft_malloc(char **res, char *s, char c)
{
  size_t  word;
  size_t  i;
  size_t  j;

  word = 0;
  i = 0;
  while (s[i])
  {
    if (s[i] == c)
      i++;
    else
    {
      i = 0;
      while (str[i + j] && str[i + j] != c)
        j++;
      res[word] = (char *)malloc(sizeof(char) * (j + 1));
      if (!res[word])
      {
        ft_free(res, word - 1);
        return ;
      }
      ft_copy(res[word++], str + i, c);
      i += j;
    }
  }
}

char  **ft_split(char const *s, char c)
{
  char  **res;
  size_t  words;

  if (!s)
    return (0);
  words = ft_countwords(s, c);
  res = (char **)malloc(sizeof(char) * (words + 1));
  if (!res)
    return (0);
  res[words] = 0;
  ft_malloc(res, s, c);
  return (res);
}