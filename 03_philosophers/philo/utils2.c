/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:41:29 by minjinki          #+#    #+#             */
/*   Updated: 2023/04/10 18:13:40 by minjinki         ###   ########.fr       */
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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = (void *)malloc(count * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, count * size);
	return (res);
}
