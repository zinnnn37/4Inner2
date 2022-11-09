#include <unistd.h>
// (unsigned char)argv[i][j] 안 해서 그런가.............. 개빡쳐~!~!~!~!
int main(int argc, char *argv[])
{
	int visited[256] = {0,};
	int i = 2, j;

	if (argc == 3)
	{
		while (i > 0)
		{
			j = 0;
			while (argv[i][j])
			{
				if (i == 2 && visited[(unsigned char)argv[i][j]] == 0)
					visited[(unsigned char)argv[i][j]] = 1;
				else if (i == 1 && visited[(unsigned char)argv[i][j]] == 1)
				{
					write(1, &argv[i][j], 1);
					visited[(unsigned char)argv[i][j]] = 2;
				}
				j++;
			}
			i--;
		}
	}
	write(1, "\n", 1);
	return 0;
}