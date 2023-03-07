/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:49:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/07 12:53:04 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutex(t_data *data)
{
	int		i;
	t_mutex	*mutex;

	i = 0;
	mutex = (t_mutex *)malloc(sizeof(t_mutex) * (data->nums + 3));
	data->mutex = mutex;
	while (i++ < data->nums + 3)
	{
		if (pthread_mutex_init(mutex++, NULL))
			return (print_error("Fail to init mutex"));
	}
	data->mprint = &data->mutex[data->nums];
	data->mfork = &data->mutex[data->nums + 1];
	data->mdie = &data->mutex[data->nums + 2];
	return (SUCCESS);
}

int	create_philo(t_data *data)
{
	t_philo		*tmp;
	t_philo		*new;
	static int	id;

	new = (t_philo *)calloc(data->nums, sizeof(t_philo));
	if (!new)
		return (FAILURE);
	if (!(data->philo))
		data->philo = new;
	else
	{
		tmp = data->philo;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	new->data = data;
	new->philo_id = ++id;
	new->lfork = &data->mutex[id - 1];
	new->rfork = &data->mutex[id % data->nums];
	return (SUCCESS);
}

int	create_thread(t_data *data)
{
	int	i;

	i = 0;
	data->philo = NULL;
	// 함수 안에서 생성 했는데 위에서 data->philo가 비었는지 확인함
	// 쓰레기 값 들어갈 수도 있으니까 NULL로 초기화
	while (i++ < data->nums)
	{
		if (create_philo(data))
			return (print_error("Fail to init t_philo"));
	}
	return (SUCCESS);
}

int	init_philo(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (print_error("Check the number of args"));
	if (!ft_atoi(av[1], &data->nums) || !ft_atoi(av[2], &data->ttdie)
		|| !ft_atoi(av[3], &data->tteat) || !ft_atoi(av[4], &data->ttsleep))
		return (print_error("Check if the arguments are valid"));
	if (ac == 6 && !ft_atoi(av[5], &data->limit))
		return (print_error("Check if the arguments are valid"));
	else if (ac == 5)
		data->limit = 0;
	data->status = ALIVE;
	data->full = 0;
	if (create_mutex(data) || create_thread(data))
		return (FAILURE);
	if (data->nums <= 1)
		return (FAILURE);
	return (SUCCESS);
}
