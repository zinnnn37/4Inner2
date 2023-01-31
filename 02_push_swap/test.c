/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:31:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 14:31:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("%d\n\n", argc);
	for (int i = 1; i < argc; i++)
		printf("%s\n", argv[i]);
	return (0);
}
