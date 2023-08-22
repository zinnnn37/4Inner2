/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:23:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/22 14:29:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	ft_error(char *s)
{
	while (*s)
		write(2, s++, 1);
	return (1);
}

int	ft_cd(char **av, int i)
{
	if (i != 2)
		return (ft_error("error: cd: bad arguments\n"));
	else if (chdir(av[1]) == -1)
		return (ft_error("error: cd: cannot change directory to "), ft_error(av[1]), ft_error("\n"));
	return (0);
}

int	ft_exec(char **av, char **env, int i)
{
	int	fd[2];
	int	stat;
	int	piped;

	if (av[i] && *(av[i]) == '|')
		piped = 1;
	else
		piped = 0;

	if (piped && pipe(fd) == -1)
		return (ft_error("error: fatal\n"));

	int	pid = fork();

	if (pid == 0)
	{
		av[i] = 0;
		if (piped && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return (ft_error("error: fatal\n"));
		execve(*av, av, env);
		return (ft_error("error: cannot execute "), ft_error(*av), ft_error("\n"));
	}

	waitpid(pid, &stat, 0);
	if (piped && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return (ft_error("error: fatal\n"));
	return (WIFEXITED(stat) && WEXITSTATUS(stat));
}

int	main(int ac, char **av, char **env)
{
	int	i = 0, stat = 0;

	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i;
			i = 0;
			while (av[i] && *(av[i]) == '|' && *(av[i]) == ';')
				i++;
			if (!strcmp(*av, "cd"))
				stat = ft_cd(av, i);
			else if (i)
				stat = ft_exec(av, env, i);
		}
	}
	return (stat);
}
