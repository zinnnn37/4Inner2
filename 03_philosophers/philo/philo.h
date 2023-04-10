/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:26 by minjinki          #+#    #+#             */
/*   Updated: 2023/04/10 18:34:16 by minjinki         ###   ########.fr       */
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
# define ERROR -1

# define MAX_INT 2147483647
# define MIN_INT -2147483648

/*
**status of philos
*/
# define ALIVE 0
# define DEAD 1
# define HUNGRY	2
# define EATING 3
# define SLEEPING 4
# define THINKING 5

# define FORK_MSG "has taken a fork"
# define EAT_MSG "is eating"
# define SLEEP_MSG "is sleeping"
# define THINK_MSG "is thinking"
# define DEAD_MSG "died"

typedef int				t_bool;
typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	int				id;	// index of philo
	t_state			state;
	t_bool			is_dead;
	t_mutex			*lfork;		// left fork
	t_mutex			*rfork;		// right fork
	size_t			last_eat;
	int				eat_cnt;
	t_mutex			*mtx;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int		nums;		// number of philo
	int		ttdie;		// time to die
	int		tteat;		// time for eating
	int		ttsleep;	// time for sleeping
	int		limit;		// number of times philo must eat
	size_t	start_time;
	t_mutex	*mprint;	// print mutex
	t_mutex	*mdie;		// die mutex
	t_mutex	*forks;		// fork mutex
	t_philo	*philos;	// philo struct
}	t_data;

/*
** fork.c
*/
t_bool	init_forks(t_data *data);
void	pick_fork(t_forks *fork);
void	put_fork(t_forks *fork);

/*
** free.c
*/
void	free_all(t_data *data);
void	destroy_philo(t_philo *philo);

/*
** init.c
*/
t_bool	init(int ac, char **av, t_data *data);

/*
** lifecircle.c
*/
void	lifecircle(t_philo *philo);

/*
** philo.c
*/
void	create_philo(t_data *data);
void	lock_philo(t_philo *philo);
void	unlock_philo(t_philo *philo);

/*
** philo_utils.c
*/
size_t	get_cur_time(void);

/*
** utils.c
*/
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
int		ft_strlen(char *s);
int		print_error(char *s);

/*
** utils2.c
*/
int		ft_atoi(const char *str, int *data);
void	*ft_calloc(size_t count, size_t size);

#endif