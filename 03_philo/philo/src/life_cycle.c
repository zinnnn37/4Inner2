/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_cycle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:06:16 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/29 11:06:16 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	take_forks(t_philo *p)
{
	if (pthread_mutex_lock(p->lfork) == SUCCESS)
		print_msg(p, FORK_MSG);
	else
		pthread_mutex_lock(&(p->data->mmain));
	if (pthread_mutex_lock(p->lfork) == SUCCESS)
		print_msg(p, FORK_MSG);
	else
		pthread_mutex_lock(&(p->data->mmain));
}

void	eating(t_philo *p)
{
	p->status = EATING;
	print_msg(p, EAT_MSG);
	p->die_cnt = get_time(); // 얘도 함수 내 변수로 뺄 수 있으면 빼기
	while (get_time() - p->die_cnt < p->data->tteat)
		usleep(100);
	(p->eat_cnt)++;
	if (p->eat_cnt == p->data->must_eat && !(p->is_full))
	{
		p->is_full = TRUE;
		p->data->full_cnt++;
	}
	pthread_mutex_unlock(p->lfork);
	pthread_mutex_unlock(p->rfork);
}

void	sleeping(t_philo *p)
{
	uint64_t	start;

	p->status = SLEEPING;
	start = get_time();
	print_msg(p, SLEEP_MSG);
	while (get_time() - start < p->data->ttsleep)
		usleep(100);
}

void	thinking(t_philo *p)
{
	p->status = THINKING;
	print_msg(p, THINK_MSG);
}
