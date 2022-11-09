#include <unistd.h>

int main(int argc, char **argv)
{
	int visited[256] = { 0, };
	int i = 1, j;

	if (argc == 3)
	{
		j = 0;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (visited[(unsigned char)argv[i][j]] == 0)
				{
					visited[(unsigned char)argv[i][j]] = 1;
					write(1, &argv[i][j], 1);
				}
				j++;
			}
			i++;
		}
	}
	return 0;
}