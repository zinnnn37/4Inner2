/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 14:10:26 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/10 14:10:26 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->mtx);
}

void	put_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->mtx);
}
