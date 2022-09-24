/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:08:36 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/24 18:20:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	save_next(t_list **head, t_list *cur, char *next)
{
	char	*tmp;

	if (next)
		tmp = ft_strndup(next + 1, ft_strlen(next + 1));
	else
		tmp = ft_strndup("", 0);
	if (!tmp)
		return (0);
	free(cur->buf);
	cur->buf = tmp;
	if (ft_strlen(cur->buf) == 0)
		ft_lst_del_node(head, cur);
	return (1);
}

char	*get_line(t_list **head, t_list *cur, char	*next)
{
	char	*line;
	int		check_null;

	if (!next)
	{
		if (!*(cur->buf))
		// 이거 안 하고 dup 한 다음에 밑에서 !*line Null 반환하면 메모리 릭(cur->buf 문제인가)
			return (NULL);
		else
			line = ft_strndup(cur->buf, ft_strlen(cur->buf));
	}
	else
		line = ft_strndup(cur->buf, next - (cur->buf) + 1);
	if (!line)
		return (NULL);
	check_null = save_next(head, cur, next);
	if (check_null == 0)
	{
		free(line);
		return (NULL);
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
		// byte < BUFFER_SIZE 없으면 empty 등에서 timeout.. 외?
		// 일단 그건 모르겟고 이걸 안 넣으면 buf ~ eof까지 \n이 없을 때
		// + BUFFER_SIZE보다 적은 값을 읽어들일 때 계속 읽게 되고
		// 그렇게 되면 밑에서 byte < 0일 때 NULL을 반환하므로
		// 뒷 꽁다리 부분을 출력할 수 없긴 해서 꼬옥 필요함..
			break ;
		byte = read(cur->fd, buf, BUFFER_SIZE);
		if (byte < 0)
			return (NULL);
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
	new->buf = ft_strndup("", 0);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cur = get_fd(&head, fd);
	if (!cur)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_lst_del_node(&head, cur));
	line = read_file(&head, cur, buf);
	free(buf);
	if (!line)
		return (ft_lst_del_node(&head, cur));
	return (line);
}
