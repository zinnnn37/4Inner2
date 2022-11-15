/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:31:14 by minjinki          #+#    #+#             */
/*   Updated: 2022/11/15 15:30:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"
#include "./include/libft.h"

void	print_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(1, str, len);
	exit(1);
}
