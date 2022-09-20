/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:36:43 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/20 12:01:02 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"
#include <stdio.h>

t_list	*get_fd(t_list **head, int fd)
{
	t_list	*cur;
	t_list	*new;

	cur = *head;
	while (cur && (cur->fd != fd))
		cur = cur->next;
	if (cur)
		return (cur);
	new = (t_list *)malloc(sizeof(t_list));
	new->fd = fd;
	printf("1");
	new->content = ft_strdup("", 0);
	if (!(new->content))
	{
		free(cur);
		cur = NULL;
		return (NULL);
	}
	new->next = *head;
	*head = new;
	return (new);
}

int read_file(t_list *cur, char *buf)
{
	char	*tmp;
	char	*next;
	int		byte;

	if (!buf)
		return (0);
	while (1)
	{
		next = ft_strchr(cur->content, '\n');
		if (next) // at least one sentence remain
			return (1);
		byte = read(cur->fd, buf, BUFFER_SIZE);
		if (byte < 0) // EOF > exit
			return (0);
		buf[byte] = '\0';
		tmp = ft_strjoin(cur->content, buf);
		if (!tmp)
			return (0);
		free(cur->content);
		cur->content = tmp;
	}
}

char	*get_line(t_list *cur)
{
	char	*res;	
	int		i;

	if (!(cur->content))
		return (NULL);
	i = 0;
	while (cur->content[i] && cur->content[i] != '\n')
		i++;
	res = ft_strdup(cur->content, i);
	free(cur->content);
	cur->content = ft_strdup(cur->content + i, ft_strlen(cur->content) - i - 1);
	return (res);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*cur;
    char            *buf;
	char			*line;
    int             status;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cur = get_fd(&head, fd);
	if (!cur)
		return (NULL);
	buf = (char *)malloc(sizeof(char) + (BUFFER_SIZE + 1));
    status = read_file(cur, buf);
	free(buf);
	if (status == 0)
	{
		ft_lstdel(&head, cur);
		return (NULL);
	}
	line = get_line(cur);
	if (!line)
		return (NULL);
	return (line);
}
