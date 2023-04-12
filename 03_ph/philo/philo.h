/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:03:15 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/12 09:03:15 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlibs.h>
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

# define DEAD 0
# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define FORK 4

typedef t_bool			int;
typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				num_philos;
	time_t			ttdie;
	time_t			tteat;
	time_t			ttsleep;
	int				must_eat;
	time_t			start_time;
	int				dead;
	pthread_t		monitor;
	pthread_mutex_t	*mforks;
	pthread_mutex_t	mprint;
	pthread_mutex_t	mdead;
	t_philo			**philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	time_t			last_eat;
	int				status;
	pthread_t		meal;
	int				fork[2];
	t_data			*data;
}	t_philo;