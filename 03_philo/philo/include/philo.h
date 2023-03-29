/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:08:55 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/29 09:08:55 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

# define SUCCESS 0
# define FAILURE 1

# define MAX_INT 2147483647

# define ODD 1
# define EVEN 0

# define THINKING 0
# define EATING 1
# define SLEEPING 2
# define FORKS 3
# define DEAD 4

# define FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEAD_MSG "died"

typedef int	t_bool;

typedef struct	s_philo
{
	int				id;
	int				status;
	t_bool			is_full;
	int				eat_cnt;
	uint64_t		die_cnt;
	struct s_data	*data;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
}	t_philo;

typedef struct	s_data
{
	int				philo_nums;
	uint64_t		ttdie;
	uint64_t		tteat;
	uintptr_t		ttsleep;
	int				must_eat;
	int				full;
	t_bool			end;
	uint64_t		start_time;
	pthread_mutex_t	mmain;
	pthread_mutex_t	mprint;
	pthread_mutex_t	mdead;
	pthread_mutex_t	*mforks;
	t_philo			*philo;
}	t_data;

/*
** utils.c
*/
int	philo_atoi(char *s);

#endif