/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:02:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/23 15:25:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include "error.h"
# include "libft.h"

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	char	**env;
}	t_data;

t_data	g_data;

/******************	minishell.c	******************/
int	minishell(void);

#endif