#include <stdio.h>

int main(void)
{
	int ret;

	if ((ret = printf("%d\n", 1)) == 2)
		printf("if : %d\n", ret);
	else
		printf("else : %d\n", ret);
	return (0);
}
