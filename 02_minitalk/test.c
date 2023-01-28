/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 18:55:54 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/28 19:01:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	static char		*str = "안녕하세요\n";
	int				i;

	i = -1;
	while (str[++i])
	{
		write(1, str + i, 1);
		write(1, "\n", 1);
	}
	return (0);
}
