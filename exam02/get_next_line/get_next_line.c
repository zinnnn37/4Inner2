#include "get_next_line.h"

char	*ft_strjoin(char *s, char c)
{
	char	*res;
	int		len = 0;

	if (!s)
	{
		res = (char *)malloc(sizeof(char) * 2);
		res[0] = c;
		res[1] = '\0';
	}
	else
	{
		while (s[len])
			len++;
		res = (char *)malloc(sizeof(char) * (len + 2));
		int i = -1;
		while (++i < len)
			res[i] = s[i];
		res[i] = c;
		res[i+1] = '\0';
		free(s);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char	*res = NULL;
	char	c;

	if (fd < 0)
		return (NULL);
	res = ft_strjoin(res, '\0'); // 빈 문자열로 초기화
	while (read(fd, &c, 1) > 0)
	{
		res = ft_strjoin(res, c); // 줄바꿈 앞까지 붙이기
		if (c == '\n')
			break ;
	}
	return (res);
}