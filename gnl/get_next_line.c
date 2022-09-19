/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:36:43 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/19 10:46:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	next_line(t_list *cur)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (cur->content[i] && cur->content[i] != '\n')
		i++;
	if (!(cur->content[i]))
	{
		free(cur->content);
		cur->content = NULL;
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(cur->content) - i));
	j = 0;
	while (cur->content[++i])
		res[j++] = cur->content[i];
	free(cur->content);
	cur->content = res;
}

char	*get_line(t_list *cur)
{
	char	*res;
	int		i;

	if (!*(cur->content))
		return (NULL);
	i = 0;
	while (cur->content[i] && cur->content[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = -1;
	while (cur->content[++i] && cur->content[i] != '\n')
		res[i] = cur->content[i];
	if (cur->content[i] == '\n')
		res[i] = '\n';
	return (res);
}

int	read_file(t_list *cur)
{
	char	*buf;
	char	*tmp;
	size_t	byte;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	byte = read(cur->fd, buf, BUFFER_SIZE);
	while (byte >= 0)
	{
		buf[byte] = '\0';
		tmp = ft_strjoin(cur->content, buf);
		free(cur->content); // 줄 넘어가면 buf는 get_next_line에서 매개변수로 받아오기
		cur->content = tmp;
		if (ft_strchr(cur->content, '\n'))
			break ;
		byte = read(cur->fd, tmp, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
	if (byte < 0)
		return (0);
	return (1);
}

t_list	*set_curr_ptr(t_list **head_ptr, int fd)
{
	t_list	*curr_ptr;

	curr_ptr = *head_ptr;
	while (curr_ptr && (curr_ptr->fd != fd))
		curr_ptr = curr_ptr->next;
	if (curr_ptr)
		return (curr_ptr);
	curr_ptr = (t_list *)malloc(sizeof(t_list));
	if (!curr_ptr)
		return (NULL);
	curr_ptr->fd = fd;
	curr_ptr->content = ft_strndup("", 0);
	if (!(curr_ptr->content))
	{
		free(curr_ptr);
		curr_ptr = NULL;
		return (NULL);
	}
	curr_ptr->next = *head_ptr;
	*head_ptr = curr_ptr;
	return (curr_ptr);
}

char	*get_next_line(int fd)
{
	static t_list	*head_ptr;
	t_list			*curr_ptr;
	int				state;
	char			*res;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	curr_ptr = set_curr_ptr(&head_ptr, fd);
	if (!curr_ptr)
		return (NULL);
	state = read_file(curr_ptr);
	if (state == 0)
		return (NULL);
	res = get_line(curr_ptr);
	if (!res)
		return (NULL);
	next_line(curr_ptr);
	return (res);
}
