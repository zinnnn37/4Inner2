#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;
	size_t			i;

	res = (unsigned char *)malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < count * size)
		res[i++] = (unsigned char)0;
	return (res);
}

int main()
{
	char	*s;

	s = (char *)calloc(5, sizeof(char));
	for (int i = 0; i < 3; i++)
		s[i] = '0';
	for (int i = 0; i < 5; i++)
		if (s[i] == '\0')
			printf("n");
		else
			printf("%c", s[i]);
}
