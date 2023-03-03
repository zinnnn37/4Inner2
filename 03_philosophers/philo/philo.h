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
# include <stdlib.h>
# include <pthread.h>
# include <memory.h>
# include <time.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef int	t_bool;
typedef pthread_mutex_t	mutex;

typedef struct	s_philo
{
	int	pos;		// index of philo
	int	lfork;		// left fork
	int	rfork;		// right fork
	int	meals;		// flag
	int	eating;		// flag
	int	last_meal;	// time of last meal
	int	limit;		// limit counter
}	t_philo;

typedef struct	s_data
{
	int		num;	// number of philo
	int		die;	// time to die
	int		eat;	// time for eating
	int		sleep;	// time for sleeping
	int		meals;	// number of times philo must eat
	int		end;	// end flag
	int		fork;	// fork not fork()
	t_philo	*philo;	// philo struct
	mutex	mprint;	// print mutex
	mutex	*mfork;	// fork mutex
	mutex	mdie;	// die mutex
}	t_data;

/**************** init.c ***************/
// init philo

/*************** utils.c ***************/
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
t_bool	print_error(char *s);

#endif