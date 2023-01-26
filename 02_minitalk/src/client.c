/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:12:22 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/17 11:28:41 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(char *str, int *res);
void	ft_putchar(char c);
void	ft_putstr(char *str);

void	print_pid(void)
{
	ft_putstr("Client PID : ");
	ft_putnbr(getpid());
	ft_putchar('\n');
}

void	send_bits(int pid, char c)
{
	int	bit;
	int	check;

	bit = 7;
	while (bit >= 0)
	{
		check = 1 << bit;
		if (c & check)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

void	send_msg(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_bits(pid, str[i]);
		i++;
	}
	send_bits(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		print_error("Check input format: ./client server_PID message\n");
	if (ft_atoi(argv[1], &pid) == 0)
		print_error("Check if PID is number\n");
	print_pid();
	i = 0;
	if (kill(pid, 0) == -1 || pid == 0)
		print_error("Invalid PID\n");
	send_msg(pid, argv[2]);
	return (0);
}
