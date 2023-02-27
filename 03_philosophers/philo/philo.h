/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:26 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/27 15:52:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef int	t_bool;

typedef struct s_philo
{
	// philo mutex array
	// time to die
	// time to eat
	// time to sleep
	// count eat(0 default)
}	t_philo;

/**************** init.c ***************/
// init philo

/*************** utils.c ***************/
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
t_bool	print_error(char *s);

#endif