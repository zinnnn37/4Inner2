/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:08:55 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/30 14:05:50 by minjinki         ###   ########.fr       */
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

# define LFORK_MSG "has taken a left fork"
# define RFORK_MSG "has taken a right fork"
# define EAT_MSG "is eating\t"
# define SLEEP_MSG "is sleeping\t"
# define THINK_MSG "is thinking\t"
# define DEAD_MSG "died"

typedef int	t_bool;

typedef struct s_philo
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

typedef struct s_data
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
** init.c
*/
t_bool		init_data(t_data *data, int ac, int *av_nums);

/*
** run.c
*/
t_bool		run_thread(t_data *data);

/*
** life_cycle.c
*/
void		take_forks(t_philo *p);
void		eating(t_philo *p);
void		sleeping(t_philo *p);
void		thinking(t_philo *p);

/*
** monitoring.c
*/
void		*monitoring(void *data);

/*
** utils.c
*/
int			philo_atoi(char *s);
t_bool		print_error(char *s);
void		print_msg(t_philo *p, char *s);
uint64_t	get_time(void);

#endif