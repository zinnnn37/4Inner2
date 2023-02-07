#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int j;
	char c[256] = { 0, };

	if (ac == 3)
	{
		i = 0;
		while (av[1][i])
		{
			if (c[(unsigned char)[1][i]] == 0)
			{
				j = 0;
				while (av[2][j])
				{
					if (av[1][i] == av[2][j])
					{
						c[(unsigned char)[1][i]] = 1;
						write(1, &c[1][i], 1);
						break ;
					}
					j++;
				}
			}
			i++;
		}
	}
	write(1, "n", 1);
	return (0);
}
