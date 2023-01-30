/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/30 15:24:15 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAO_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		data;
	s_data	*prev;
	s_data	*next;
}	t_data;

typedef struct s_stack
{
	s_data	*top;
	s_data	*bottom;
	int		size;
}	t_stack;

/*************** command ***************/
void	sn(t_stack s, char *str);

/************* hard coding *************/
void	sort_two(t_stack a);

void	ft_putstr(char *str);
void	print_error(char *str);


#endif
