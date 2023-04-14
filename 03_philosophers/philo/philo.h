/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:15 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 14:41:31 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define SUCCESS 0
# define FAILURE 1

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef int				t_bool;
typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				num_philos;
	time_t			ttdie;
	time_t			tteat;
	time_t			ttsleep;
	int				must_eat;
	time_t			start_time;
	t_bool			end;
	pthread_t		monitor;
	pthread_mutex_t	*mforks;
	pthread_mutex_t	mprint;
	pthread_mutex_t	mdead;
	t_philo			**philos;
}	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eat_count;
	time_t			last_eat;
	pthread_mutex_t	meal;
	int				fork[2];
	t_data			*data;
}	t_philo;

/*
** parse.c
*/
t_bool			check_valid(int ac, char **av, t_data *data);

/*
** init.c
*/
t_bool			init_data(t_data *data);
t_philo			**init_philos(t_data *data);
t_bool			init_mutexes(t_data *data);
pthread_mutex_t	*init_forks(t_data *data);

/*
** philo.c
*/
void			*philosopher(void *arg);
void			thinking(t_philo *philo, int print);
void			eating_n_sleeping(t_philo *philo);

/*
** monitoring.c
*/
void			*monitoring(void *arg);
t_bool			should_be_ended(t_data *data);
t_bool			is_philo_dead(t_philo *philo);
void			set_end_flag(t_data *data, int status);
t_bool			is_simul_stopped(t_data *data);

/*
** utils.c
*/
time_t			get_cur_time(void);
void			do_usleep(t_data *data, time_t time);
void			run_delay(time_t start);
void			destroy_mutexes(t_data *data);
void			free_data(t_data *data);

/*
** calloc.c
*/
void			*ft_calloc(size_t count, size_t size);

/*
** print.c
*/
void			msg(t_philo *philo, char *s);

/*
** exit.c
*/
int				print_error(char *s, t_data *data);
void			*err_null(char *s, t_data *data);
void			free_data(t_data *data);

#endif