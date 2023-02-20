/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/20 16:19:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	pid_t	pid;
	int		status;
	int		ret;

	pid = fork();
	if (pid > 0)
	{
		printf("Parent ID : %d\n", getpid());
		ret = waitpid(pid, &status, WNOHANG);
		printf("Parent killed\n");
	}
	else if (pid == 0)
	{
		printf("Child ID : %d\n", getpid());
		usleep(100);
		printf("Child killed\n");
	}
	return (SUCCESS);
}
