/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/08 13:20:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> ////////// remove!!!

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FAILURE 1
# define SUCCESS 0

typedef int	t_bool;

typedef struct s_data
{
	int				data;
	int				rank;
	struct s_data	*prev;
	struct s_data	*next;
}	t_data;

typedef struct s_stack
{
	t_data	*top;
	t_data	*bottom;
	int		size;
}	t_stack;

typedef struct s_info
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	int		chunk;
}	t_info;

/**************** stack ****************/
void	create_and_add_node(t_stack *s, int data);
t_bool	is_ordered_not_dup(t_stack *a);

void	print_nodes(t_stack *a, t_stack *b);
void	print_ranks(t_stack *a);

/*************** ranking ***************/
void	set_rank(t_stack *a);

/**************** parse ****************/
void	get_numbers(int ac, char **av, t_stack *s);

/*************** command ***************/
int		sn(t_stack *s, char *str);
int		rn(t_stack *s, char *str);
int		rrn(t_stack *s, char *str);
void	pn(t_stack *from, t_stack *to, char *str);

/************* hard coding *************/
void	sort_small_numbers(t_stack *a, t_stack *b);
void	sort_two(t_stack *a);

/************** sort utils *************/
void	rotate_till_min(t_stack *s);

/**************** utils ****************/
void	print_error(void);
void	ft_exit(char *str);

#endif
