/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:26 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/07 12:48:46 by minjinki         ###   ########.fr       */
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

/*********** status of philos  **********/
# define ALIVE 0
# define DEAD 1
# define FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEAD_MSG "died"

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
	pthread_t		tid;
	int				philo_id;	// index of philo
	t_mutex			*lfork;		// left fork
	t_mutex			*rfork;		// right fork
	int				eat_cnt;
	size_t			begin;
	size_t			last_eat;
	size_t			cur_time;
	struct s_data	*data;
	struct s_philo	*next;
}	t_philo;

typedef struct	s_data
{
	int		nums;	// number of philo
	int		ttdie;	// time to die
	int		tteat;	// time for eating
	int		ttsleep;// time for sleeping
	int		limit;	// number of times philo must eat
	size_t	status;	// philo alive or dead
	size_t	full;
	t_mutex	*mutex;
	t_mutex	*mprint;// print mutex
	t_mutex	*mfork;	// fork mutex
	t_mutex	*mdie;	// die mutex
	t_philo	*philo;	// philo struct
}	t_data;

/**************** init.c ***************/
int	init_philo(int ac, char **av, t_data *data);

/*************** utils.c ***************/
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
int		print_error(char *s);

/************** utils2.c ***************/
int		ft_atoi(const char *str, int *data);
void	*ft_calloc(size_t count, size_t size);

#endif