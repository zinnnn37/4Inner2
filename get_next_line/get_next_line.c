/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:19:12 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/22 12:26:52 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_next(t_list **head, t_list *cur, char *next, size_t len)
{
	char	*tmp;
	char	*line;

	line = ft_strndup(cur->buf, len); // +1 은 \n 때문에
	if (!line || !*line)
		return (NULL);
	if (next)
		tmp = ft_strndup(next + 1, ft_strlen(next + 1));
	else
		tmp = ft_strndup("", 0);
	if (!tmp)
		return (NULL);
	free(cur->buf);
	cur->buf = tmp;
	if (ft_strlen(cur->buf) == 0)
		ft_lst_del_node(head, cur);
	return (line);
}

char	*get_line(t_list **head, t_list *cur, char	*next)
{
	char	*line;

	if (next)
		line = save_next(head, cur, next, next - (cur->buf) + 1);
	else
	{
		if (!*(cur->buf))
			return (NULL);
		else
			line = save_next(head, cur, next, ft_strlen(cur->buf));
	}
	return (line);
}

char	*read_file(t_list **head, t_list *cur, char *buf)
{
	char	*next;
	char	*tmp;
	int		byte;

	byte = BUFFER_SIZE;
	while (1)
	{
		next = ft_strchr(cur->buf, '\n');
		if (next || byte < BUFFER_SIZE)
			break ; // more than 1 sentence remain
		byte = read(cur->fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (NULL); // eof, no characters remain
		buf[byte] = '\0';
		tmp = ft_strjoin(cur->buf, buf);
		if (!tmp)
			return (NULL);
		free(cur->buf);
		cur->buf = tmp;
	}
	return (get_line(head, cur, next));
}

t_list	*get_fd(t_list **head, int fd)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *head;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->buf = ft_strndup("", 0); // empty string
	if (!(new->buf))
	{
		free(new);
		new = NULL;
		return (NULL);
	}
	new->fd = fd;
	new->next = *head;
	*head = new;
	return (new);
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*cur;
	char			*buf;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cur = get_fd(&head, fd);
	if (!cur)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_lst_del_node(&head, cur));
	line = read_file(&head, cur, buf);
	free(buf); // 공교롭게도 줄이 넘는다...
	if (!line)
		return (ft_lst_del_node(&head, cur));
	return (line);
}


int main(void)
{
	char	*s;
	while ((s = get_next_line(1)))
	{
		printf("res: %s\n", s);
	}
}


/*
int main(void)
{
	int 	fd;
	char	*s;

	fd = open("test", O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		printf("%s\n", s);
	}
}
*/