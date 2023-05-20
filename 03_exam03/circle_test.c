#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARGERR "argument"
#define CORR "Operation file corrupted"

int	print_error(char *s)
{
	int	i = 0;

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

int	main(int ac, char **av)
{
	FILE	*file;
	int		width, height, ret;
	char	back, c, draw;
	float	Xa, Ya, Xb, Yb, radius, dist;

	if (ac != 2)
		return (print_error(ARGERR));
	if (!(file = fopen(av[1], "r"))) // open as readonly?
		return (print_error(CORR));
	if ((fscanf(file, "%d %d %c\n", &width, &height, &back)) != 3)
		return (print_error(CORR));
	if (!(width > 0 && width <= 300) || !(height > 0 && height <= 300))
		return (print_error(CORR));

	char	buf[(width * height)];	// save matrix as 1D array

	for (int i = 0; i < (width * height); i++)
		buf[i] = back;
	while ((ret = fscanf(file, "%c %f %f %f %c\n", &c, &Xa, &Ya, &radius, &draw)) == 5)
	{
		if ((c != 'c' && c != 'C') || radius <= 0.00000000)
			return (print_error(CORR));
		for (int y = 0; y < height; y++)
		{
			Yb = (float)y;
			for (int x = 0; x < width; x++)
			{
				Xb = (float)x;
				dist = sqrtf((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb));
				if (dist <= radius)
				{
					if ((c == 'c' && radius - dist < 1.00000000) || (c == 'C'))
						buf[(y * width) + x] = draw;
				}
			}
		}
	}
	if (ret != -1)
		return (print_error(CORR));
	
	return (ft_draw(buf, width, height));
}