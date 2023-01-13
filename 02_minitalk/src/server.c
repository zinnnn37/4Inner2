/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:15:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/12 15:24:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_pid()
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("server pid : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	print_message()
{
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		print_error("Check input format: ./server\n");
	print_pid();
	print_message();
}