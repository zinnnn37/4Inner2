/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:13:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/28 13:50:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef struct s_client
{
	pid_t				pid;
	int					bit;
	char				*msg;
	struct sigaction	act;
}	t_client;

typedef struct s_server
{
	pid_t				pid;
	char				*msg;
	struct sigaction	act;
}	t_server;

t_client	g_client;
t_server	g_server;

char	*ft_join(char *s, char c);
char	*ft_strdup(const char *s);
char	*ft_strtrim(char const *s1);

int		ft_atoi(char *str, int *res);
int		ft_strlen(const char *s);

void	c_hdr_connection(int signo, siginfo_t *info, void *content);
void	print_error(char *str);
void	ft_kill(pid_t pid, int signo);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
void	send_msg(void);

#endif
