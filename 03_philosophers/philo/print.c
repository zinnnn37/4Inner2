/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:29:33 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/15 12:29:33 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	display_msg(t_philo *philo, char *msg)
{
	lock_philo(philo);
	if (!(philo->is_dead))
		printf("%zu %u %s\n", get_cur_time() / 1000, philo->id, msg);
	unlock_philo(philo);
}
// philo가 아니라 mprint로 mutex 바꿀지 말지 실행해보고 결정
