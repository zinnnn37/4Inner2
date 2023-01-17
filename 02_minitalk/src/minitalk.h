/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:13:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/17 11:54:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "../libft/libft.h"

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef struct s_data
{
	pid_t	pid;
	char	*msg;
}	t_data;

void	c_hdr_connect(int signo);
void	c_hdr_msg(int signo, siginfo_t *info, void *content);
void	print_error(char *str);
void	s_hdr_connect(int signo, siginfo_t *info, void *content);
void	s_hdr_msg(int signo, siginfo_t *info, void *content)

#endif