/*
#include "get_next_line.h"

char	*ft_join(char *buf, char *new)
{
	char	*res;

	res = ft_strjoin(buf, new);
	free(buf);
	return (res);
}

char	*ft_read(int fd, static char *res) // static char이랑 char로 다르게 썼을 때 차이점이 있으려나
{
	char	*buf;
	int		byte;

	if (!res) // 할당이 되어있지 않는 경우 할당 > 처음 읽는 경우?
		res = ft_calloc(1, sizeof(char)); // join 시 하나라도 null이면 함수 바로 종료라서..
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte = 1;
	while (byte > 0) // byte가 0인 경우 (eof인 경우) 여기서 빠져나감
	{
		byte = read(fd, buf, BUFFER_SIZE);
		if (byte == -1) // 읽기 실패
		{
			free(buf);
			return (NULL);
		}
		buf[byte] = 0; // 마지막 널문자
		res = ft_join(res, buf); // 기존 문장(res)와 받은 문장(buf) 합치기
		if (ft_strchr(buf, '\n')) // 받은 문장에 줄바꿈 문자가 있는 경우 한 문장의 끝 > 문장을 더 받아오지 않고 종료
			break ;
	}
	free(buf);
	return (res);
}

char	*ft_get_line(char *buf)
{
	char	*res;
	int		i;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf[i] && buf[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char)); // 줄바꿈이랑 널문자 2개
	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		res[i] = buf[i];
		i++;
	}
	if (buf[i] && buf[i] == '\n') // 파일 끝이면 줄바꿈 붙이지 않아도 되니까
		res[i] == '\n';
	return (res);
}

char	*ft_next_line(char *buf)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i]) // EOF
	{
		free(buf); // buf 메모리 해제
		return (NULL);
	}
	res = ft_calloc(ft_strlen(buf) - i, sizeof(char))
	// buf 길이 - i(줄바꿈 문자의 인덱스) > 길이랑 인덱스는 1 차이 나니까 +1 안해줌 > 터지면 +1하기)
	// calloc 내부에서 null 가드 해줘서 따로 널 가드 필요 x
	j = 0;
	while (buf[i])
		res[j++] = buf[i++];
	free(buf); // buf 내용 다 res에 옮겼으니 해제
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer; // 함수가 종료되어도 값을 지니고 있게끔 static으로 선언
	char		*line;
	// read(파일 디스크립터, 파일을 읽어들일 버퍼, 버퍼의 크기)
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) // read 반환값: 읽어들인 바이트 수. 읽기 실패 시 -1
	// 3번째 경우는 파일디스크립터가 유효한지 확인용. 실패 시 -1, 성공 시 0
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer) // 읽기 실패
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer); // 다음에 읽어들일 문장 저장
	return (line);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:39:46 by minjinki          #+#    #+#             */
/*   Updated: 2022/07/25 15:54:16 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *buf, char *next)
{
	char	*res;

	res = ft_strjoin(buf, next);
	free(buf);
	return (res);
}

// buf = before tmp = next
char	*ft_read_file(int fd, char *buf)
{
	char	*tmp;
	size_t	byte;

	if (!buf)
		buf = ft_calloc(1, sizeof(char));
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = '\0'; // 길이가 2인데 4만큼 읽으면 값, 값, 쓰레기값, 쓰레기값 이렇게 담김 >> 그래서 '\0'을 넣어주는 것
		buf = ft_join(buf, tmp);
		if (ft_strchr(buf, '\n'))
			break;
	}
	free(tmp);
	return (buf);
}

char	*ft_get_line(char *buf)
{
	char	*res;
	size_t	i;

	if (!*buf)
		return (NULL); // eof 확인용.. 안 넣으면 '\0'만 들어가서 안 끝날 것 같음
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	res = ft_calloc(i + 2, sizeof(char));
	(!res)
		return (NULL);
	i = -1;
	while (buf[++i] && buf[i] == '\n')
		res[i] = buf[i];
	if (buf[i] == '\n')
		res[i] = '\n';
	return (res);
}

char	*ft_next_line(char *buf)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i]) // 다음 줄 없음
	{
		free(buf);
		return (NULL);
	}
	res = ft_calloc(strlen(buf) - i, sizeof(char));
	j = 0;
	while (buf[++i])
		res[j++] = buf[i];
	free(buf);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_read_file(fd, buf);
	if (!buf)
		return (NULL);
	line = ft_get_line(buf);
	buf = ft_next_line(buf);
	return (line);
}