/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:32:29 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/18 11:59:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

int	main(int argc, char **argv)
{
	t_pos	pos;
	int		cur[2];

	pos.x = 1;
	pos.y = 2;
	cur[0] = pos.x;
	cur[1] = pos.y; // 아마 선언과 동시에 초기화 해야 {} 형태로 초기화 가능한 듯 ?
	cur[0]++;
	cur[1]--;
	printf("%d %d\n", pos.x, pos.y);
	printf("%d %d\n", cur[0], cur[1]);
}
