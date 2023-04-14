/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:17:56 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 11:47:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str, int *data)
{
	long long	ans;
	size_t		i;

	i = 0;
	ans = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		i++;
		if (ans > MAX_INT)
			return (FALSE);
	}
	if (str[i] && (str[i] < '0' || '9' < str[i]))
		return (FALSE);
	*data = (int)(ans);
	return (TRUE);
}

t_bool	philo_atoi(char	*s, time_t *res)
{
	long long	n;
	int			i;

	i = -1;
	n = 0;
	while ('0' <= s[++i] && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		if (n > MAX_INT)
			return (FALSE);
	}
	if (s[i] && (s[i] < '0' || '9' < s[i]))
		return (FALSE);
	*res = (time_t)n;
	return (TRUE);
}

t_bool	check_valid(int ac, char **av, t_data *data)
{
	if (!ft_atoi(av[1], &data->num_philos) || data->num_philos < 1)
		return (print_error("Check if the arguments are valid: av[1]", data));
	if (!philo_atoi(av[2], &data->ttdie) || data->ttdie < 0)
		return (print_error("Check if the arguments are valid: av[2]", data));
	if (!philo_atoi(av[3], &data->tteat) || data->tteat < 0)
		return (print_error("Check if the arguments are valid: av[3]", data));
	if (!philo_atoi(av[4], &data->ttsleep) || data->ttsleep < 0)
		return (print_error("Check if the arguments are valid: av[4]", data));
	if (ac == 6 && (!ft_atoi(av[5], &data->must_eat) || data->must_eat < 0))
		return (print_error("Check if the arguments are valid: av[5]", data));
	else if (ac == 5)
		data->must_eat = -1;
	return (SUCCESS);
}
