/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:17:56 by MJKim             #+#    #+#             */
/*   Updated: 2023/04/13 11:09:10 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	philo_atoi(char	*s, int *res)
{
	long long	n;
	int			i;

	i = -1;
	ans = 0;
	while ('0' <= str[++i] && str[i] <= '9')
	{
		ans = ans * 10 + (str[i] - '0');
		if (ans > MAX_INT)
			return (FALSE);
	}
	if (str[i] && (str[i] < '0' || '9' < str[i]))
		return (FALSE);
	*data = (int)(ans);
	return (TRUE);
}

t_bool	check_valid(int ac, char **av, t_data *data)
{
	if (!ft_atoi(av[1], &data->nums) || data->nums < 1)
		return (print_error("Check if the arguments are valid: av[1]"));
	if (!ft_atoi(av[2], &data->ttdie) || data->ttdie < 0)
		return (print_error("Check if the arguments are valid: av[2]"));
	if (!ft_atoi(av[3], &data->tteat) || data->tteat < 0)
		return (print_error("Check if the arguments are valid: av[3]"));
	if (!ft_atoi(av[4], &data->ttsleep) || data->ttsleep < 0)
		return (print_error("Check if the arguments are valid: av[4]"));
	if (ac == 6 && (!ft_atoi(av[5], &data->limit) || data->limit < 0))
		return (print_error("Check if the arguments are valid: av[5]"));
	else if (ac == 5 || av[5] == 0)
		data->limit = -1;
	return (TRUE);
}
