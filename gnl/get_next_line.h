/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:36:43 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/20 10:27:05 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_lstdel(t_list **head_ptr, t_list *curr_ptr);

#endif