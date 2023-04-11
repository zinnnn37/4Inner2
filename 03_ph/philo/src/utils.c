/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:55:50 by marousta          #+#    #+#             */
/*   Updated: 2021/12/23 16:05:40 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <common/utils.h>
#include <unistd.h>

t_usize	get_now(void)
{
	static time_t	first_ts = 0;
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (first_ts == 0)
		first_ts = current_time.tv_sec * 1000000 + current_time.tv_usec;
	return ((current_time.tv_sec * 1000000 + current_time.tv_usec) - first_ts);
}

static t_i64	ft_atol(const t_string str)
{
	t_i32	i;
	t_i64	result;
	t_i32	negative;

	i = 0;
	result = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		negative = -negative;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * negative);
}

static t_bool	ft_strisnumber(const t_string str)
{
	t_i32	i;
	t_bool	dot;

	if (!str || !str[0])
		return (FALSE);
	if (str[0] == '-' && !str[1])
		return (FALSE);
	i = -1;
	dot = FALSE;
	while (str[++i])
	{
		if (i == 0 && str[0] == '-')
			continue ;
		if (!dot && str[i] == '.')
			dot = TRUE;
		else if (!(str[i] >= '0' && str[i] <= '9') || (dot && str[i] == '.'))
			return (FALSE);
	}
	return (TRUE);
}

t_bool	ft_satoi(t_i32 *ret, const t_string str)
{
	t_i64	n;

	if (!ft_strisnumber(str))
		return (FALSE);
	n = ft_atol(str);
	if (n > 2147483647 || n < -2147483648)
		return (FALSE);
	*ret = n;
	return (TRUE);
}

void	ft_usleep(t_u64 time)
{
	t_u64	past;

	past = get_now();
	while (TRUE)
	{
		if (get_now() - past >= time)
			break ;
		usleep(50);
	}
}
