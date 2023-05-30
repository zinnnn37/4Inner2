#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ARGERR "argument"
#define CORR "Operation file corrupted"

int	print_error(char *s, FILE *file)
{
	int	i = 0;

	if (file)
		fclose(file);

	while (s[i])
		i++;
	write(1, "Error: ", 7);
	write(1, s, i);
	write(1, "\n", 1);
	return (1);
}

int	ft_draw(char *buf, int w, int h)
{
	for (int y = 0; y < h; y++)
	{
		write(1, buf + (y * w), w);
		write(1, "\n", 1);
	}
	return (0);
}

int	is_rect(float x, float y, float xcheck, float ycheck, float fwidth, float fheight)
{
	if (xcheck < x || x + fwidth < xcheck || ycheck < y || y + fheight < ycheck)
		return (0);
	if (xcheck - x < 1.00000000 || x + fwidth - xcheck < 1.00000000 \
		|| ycheck - y < 1.00000000 || y + fheight - ycheck < 1.00000000)
		return (2);
	return (1);
}

int	main(int ac, char **av)
{
	FILE	*file;
	int		width, height, ret;
	char	back, c, draw;
	float	X, Y, Xcheck, Ycheck, fwidth, fheight;

	if (ac != 2)
		return (print_error(ARGERR, NULL));
	if (!(file = fopen(av[1], "r")))
		return (print_error(CORR, NULL));
	if ((fscanf(file, "%d %d %c\n", &width, &height, &back)) != 3)
		return (print_error(CORR, file));
	if (!(width > 0 && width <= 300) || !(height > 0 && height <= 300))
		return (print_error(CORR, file));

	char	buf[(width * height)];

	for (int i = 0; i < (width * height); i++)
		buf[i] = back;

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", &c, &X, &Y, &fwidth, &fheight, &draw)) == 6)
	{
		if ((c != 'r' && c != 'R') || fwidth < 1.00000000 || fhieght < 1.00000000)
			return (print_error(CORR, file));
		for (int y = 0; y < height; y++)
		{
			Ycheck = (float)y;
			for (int x = 0; x < width; x++)
			{
				Xcheck = (float)x;
				if ((is_rect(X, Y, Xcheck, Ycheck, fwidth, fheight) == 2) \
					|| (is_rect(X, Y, Xcheck, Ycheck, fwidth, fheight) == 1 && c == 'R'))
					buf[(y * width) + x] = draw;
			}
		}
	}
	if (ret != -1)
		return (print_error(CORR, file));
	fclose(file);
	return (ft_draw(buf, width, height));
}