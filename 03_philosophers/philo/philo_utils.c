/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:36:21 by minjinki          #+#    #+#             */
/*   Updated: 2023/04/10 18:33:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** get current time: gap from start time
*/
size_t	get_cur_time(void)
{
	static time_t	start = 0;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (start == 0)
		start = tv.tv_sec * 1000 + tv.tv_usec;
	return ((tv.tv_sec * 1000) + (tv.tv_usec) - start);
}

void	do_usleep(size_t time)
{
	size_t	start;

	start = get_cur_time();
	while (get_cur_time() - start < time)
		usleep(50);
}

void	display_msg(t_philo *philo, char *msg)
{
	lock_philo(philo);
	if (!(philo->is_dead))
		printf("%zu %u %s\n", get_cur_time(), philo->id + 1, msg);
	unlock_philo(philo);
}
// philo가 아니라 mprint로 mutex 바꿀지 말지 실행해보고 결정
