/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:26 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/06 17:27:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <memory.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef int	t_bool;
typedef pthread_mutex_t	t_mutex;

typedef enum	e_status
{
	THINKING,
	EATING,
	HUNGRY
}	t_stat;

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
	int		limit;	// number of times philo must eat
	int		end;	// end flag
	int		fork;	// fork not fork()
	t_philo	*philo;	// philo struct
	t_mutex	mprint;	// print mutex
	t_mutex	mfork;	// fork mutex
	t_mutex	mdie;	// die mutex
}	t_data;

/**************** init.c ***************/
// init philo

/*************** utils.c ***************/
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
t_bool	print_error(char *s);

/************** utils2.c ***************/
int		ft_atoi(const char *str, int *data);
void	*ft_calloc(size_t count, size_t size);

#endif