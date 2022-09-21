/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:19:12 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/21 11:15:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*get_fd(t_list **head, int fd)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (tmp)
		return (tmp);
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->buf = ft_strndup("", 0); // empty string
	if (!(tmp->buf))
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp->fd = fd;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}
/*
char	*read_file(t_list *cur, char *buf)
{
	char	*tmp;
	int		byte;

}
*/
char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list	*cur;
	char	*buf;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	cur = get_fd(&head, fd);
	if (!cur)
		return (NULL);
	printf("%d\n", cur->fd);
	return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_lst_del_node(&head, cur));
}


int main(void)
{
	for (int i = 1; i < 6; i++)
	{
		get_next_line(i%2);
	}
}
