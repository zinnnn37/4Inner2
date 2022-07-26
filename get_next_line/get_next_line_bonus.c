#include "get_next_line_bonus.h"

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
	buf = ft_calloc(OPEN_MAX + 1, sizeof(char **));
	buf[fd] = ft_read_file(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	line = ft_get_line(buf[fd]);
	buf[fd] = ft_next_line(buf[fd]);
	return (line);
}