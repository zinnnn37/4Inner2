/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:01:59 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/29 10:01:59 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*life_cycle(void *p)
{
	(t_philo *)p;
	p->die_cnt = p->data->start_time;
	while (!(p->data->end))
	{
		take_forks(p);
		eating(p);
		sleeping(p);
		thinking(p);
		usleep(100);
	}
	return ((void *)SUCCESS);
}

t_bool	run_philo(t_data *data, int n)
{
	void		*p;
	pthread_t	tid;

	while (n < data->philo_nums)
	{
		p = (void *)(&(data->philo[n]));
		if (pthread_create(&tid, NULL, &life_cycle, p) != SUCCESS)
			return (FALSE);
		pthread_detach(tid);
		i += 2;
	}
	if (n % 2 == 0)
		usleep(500 * data->tteat);
	return (TRUE);
}

t_bool	run_thread(t_data *data)
{
	pthread_t	tid;

	data->start_time = get_time();
	if (!run_philo(data, EVEN) || !run_philo(data, ODD))
		return (FALSE);
	if (pthread_create(&tid, NULL, &monitoring, data) != SUCCESS)
		return (FALSE);
	return (SUCCESS);
}
