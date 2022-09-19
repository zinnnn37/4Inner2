/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:36:43 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/19 14:30:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	new->content = ft_strdup("");
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

	buf = (char *)malloc(sizeof(char) + (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (1)
	{
		next = ft_strchr(cur->content, '\n');
		if (next) // EOF but remain some sentences > should not exit
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

char	*one_line(t_list *cur)
{
	char	*res;	
	int		i;

	if (!(cur->content))
		return (NULL);
	i = 0;
	while (cur->content[i] && cur->content[i] != '\n')
		i++;
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
    status = read_file(cur, buf);
	free(buf);
	if (status == 0)
		return (NULL);
	line = one_line(cur);
	if (!line)
		return (NULL);
}