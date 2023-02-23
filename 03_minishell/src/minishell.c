/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/23 12:36:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	minishell(void)
{
	char	*cmd;

	while (TRUE)
	{
		cmd = readline("minishell_$> ");
		add_history(cmd);
		free(cmd);
	}
	return (SUCCESS);
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	g_global.env = env;
	if (ac != 1)
		exit_with_code("Usage: ./minishell\n", 126);
	return (FAILURE);
}
