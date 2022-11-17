/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:49:02 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/17 11:50:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
		free(map->map[i++]);
	free(map->map);
	free(map);
}
