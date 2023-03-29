/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:21:20 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/29 09:21:20 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_bool	print_error(char *s)
{
	printf("*ERROR* %s\n", s);
	return (FALSE);
}

int	philo_atoi(char *s)
{
	int			i;
	long long	n;

	i = -1;
	n = 0;
	while (s[++i] && str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		if (res > MAX_INT)
			return (ERROR);
	}
	if (s[i] != '\0')
		return (ERROR);
	return (n);
}

void	print_msg(t_philo *p, char *s)
{
	if (p->data->is_dead == TRUE)
		return ;
	if (pthread_mutex_lock(&(p->data->mprint)) == SUCCESS)
	{
		printf("%llums\t%d\t%s\t[%d]\n",
			get_time() - p->data->start_time, p->id, s, p->eat_cnt);
		if (p->status != DEAD)
			pthread_mutex_unlock(&(p->data->mprint));
	}
}

/*
** return time in millisecond
*/
uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
