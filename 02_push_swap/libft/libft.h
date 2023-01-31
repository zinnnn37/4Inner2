/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:25:24 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 13:21:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	**ft_split(char const *s);

int		ft_atoi(const char *str, int *data);

size_t	ft_strlen(const char *s);

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);

void	ft_putstr(char *s);

#endif
