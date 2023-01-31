/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 13:17:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FAILURE 1
# define SUCCESS 0

typedef struct s_data
{
	int		data;
	struct	s_data	*prev;
	struct	s_data	*next;
}	t_data;

typedef struct s_stack
{
	t_data	*top;
	t_data	*bottom;
	int		size;
}	t_stack;

/**************** stack ****************/
void	create_and_add_node(t_stack *s, int data);
void	print_nodes(t_stack *s);

/**************** parse ****************/
void 	get_numbers(int ac, char **av, t_stack *s);

/*************** command ***************/
int		sn(t_stack *s, char *str);

/************* hard coding *************/
void	sort_two(t_stack a);

void	print_error();

#endif
