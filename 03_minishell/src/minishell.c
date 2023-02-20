/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/20 14:12:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int ac, char **av)
{
	char	*cmd;

	(void)av;
	if (ac != 1)
		return (FAILURE);
	while (TRUE)
	{
		cmd = readline("minishell_$ ");
		if (!cmd)
			break ;
		//parse(cmd);
		printf("%s\n", cmd);
		add_history(cmd);
		write(1, "a", 1);
		rl_on_new_line();
		rl_replace_line();
		rl_redisplay();
		free(cmd);
	}
	return (SUCCESS);
}
