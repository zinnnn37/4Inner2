/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:39:46 by minjinki          #+#    #+#             */
/*   Updated: 2022/09/17 17:47:00 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_files(int fd, char *buf)
{
}

t_list	*get_fd(t_list **head, int fd)
{
	t_list	*cur;
	t_list	*new;

	cur = *head;
	while (cur && cur->fd != fd)
		cur = cur->next;
	if (cur)
		return (cur);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->content = strdup("", 0); // empty string
	if (!(new->content))
	{
		free(new);
		new = NULL; // dangling pointer
		return (NULL);
	}
	new->next = *head; // linked list 맨 앞에 붙이기, 초기 *head는 0x0
	*head = new; // 맨 처음 노드 가리키게
	return (new);
}
/*
	위에 두고 return을 밑에서 한 번에 처리하면
	dangling pointer 처리한 것 때문에 new->next 접근 불가 > 에러
	if문을 밑으로 내리고 싶은데 이것도 애매한 게
	head가 가리키는 것이 메모리를 해제한 노드가 되어버림 > 정의되지 않은 행위
*/

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
		return (NULL);
	line = read_files(fd, buf);
	if (!line)
	{
		lst_del_node(&head, cur); // cur 노드 list에서 삭제 후 함수 종료
		return (NULL);
	}
	return (line);
}
