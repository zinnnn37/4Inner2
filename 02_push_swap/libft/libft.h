/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:25:24 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/14 11:33:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define MAX_INT 2147483647
# define MIN_INT -2147483648

char	**ft_split(char const *s);

char	*ft_strtrim(char const *s1, char const *set);

int		ft_atoi(const char *str, int *data);
int		ft_strcmp(const char *s1, const char *s2);

size_t	ft_strlen(const char *s);

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

void	ft_putnbr(int n);
void	ft_putstr(char *s);

#endif
