/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/16 18:06:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_sdata;

void	print_pid(void)
{
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		print_error("Check input format: ./server\n");
	print_pid();
	while (TRUE)
		pause();
}
