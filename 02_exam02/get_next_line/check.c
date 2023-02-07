#include "check.h"

char	*ft_join(char *s, char c)
{
	int len = 0;
	char *res;
	if (!s)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = c;
		res[1] = '\0';
	}
	else
	{
		while (s[len])
			len++;
		res = malloc(sizeof(char) * (len + 2));
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
	res = ft_join(res, '\0');
	while (read(fd, &c, 1) > 0)
	{
		res = ft_join(res, c);
		if (c == '\n')
			break;
	}
	return (res);
}