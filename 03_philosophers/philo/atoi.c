/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:41:29 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/06 16:08:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *data)
{
	int			minus;
	long long	ans;
	size_t		i;

	i = 0;
	minus = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			minus = -1;
	ans = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
		if (ans * minus > MAX_INT || ans * minus < MIN_INT)
			return (FALSE);
	}
	if (str[i] && (str[i] < '0' || '9' < str[i]))
		return (FALSE);
	*data = (int)(minus * ans);
	return (TRUE);
}
