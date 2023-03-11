/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:25:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/03/11 15:36:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exit_with_code(const char *s, int error)
{
	ft_putstr(s, 2);
	exit(error); // exit.. 말고 return으로 구현하기 ?
}
