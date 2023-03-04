/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/04 18:14:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int ac, char **av)
// {
// 	if (ac != 5 && ac != 6)
// 		return (print_error("Argument error"));
// 	if (!init_philo(av))
// 		return (print_error("Fail to init t_philo"));
// }

/*
	1. 구조체 초기화
	2. av 5개인지 6개인지 확인하고 limiter 0 혹은 av[5]로 초기화
	3. 
*/


/*
	홀수 짝수로 나눠서
	홀수는 왼쪽 포크부터, 짝수는 오른쪽 포크부터 집게 해서 데드락 방지
	
*/



int	main(void)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	sleep(1);
	gettimeofday(&end, NULL);
	printf("%ld, %d\n", end.tv_sec - start.tv_sec, end.tv_usec - start.tv_usec);
}
