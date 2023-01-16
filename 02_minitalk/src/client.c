/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:22 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 19:44:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_cdata;

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		print_error("Check input format: ./client server_PID message\n");
	pid = ft_atoi(argv[1]);
	if (pid == -1)
		print_error("Check if PID is number: ./client server_PID message\n");
}
