/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:29:33 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/10 16:00:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_msg(t_philo *philo, char *msg)
{
	lock_philo(philo);
	if (!(philo->is_dead))
		printf("%zu %u %s\n", get_cur_time(), philo->id + 1, msg);
	unlock_philo(philo);
}
// philo가 아니라 mprint로 mutex 바꿀지 말지 실행해보고 결정
