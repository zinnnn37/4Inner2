#include <unistd.h>

int main(int argc, char **argv)
{
	int visited[256] = { 0, };
	int i = 0, j;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (visited[argv[1][i]] == 0)
				visited[argv[1][i]] = 1;
			
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j] && visited[argv[2][j]] == 1)
				{
					visited[argv[1][i]] = 2;
					write(1, &argv[1][i], 1);
					break;
				}
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}