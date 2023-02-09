/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/09 11:13:30 by minjinki         ###   ########.fr       */
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
# define DUP 2

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
void	sort_three(t_stack *a);

/***************** sort ****************/
void	sort(t_info *info);

/************** sort utils *************/
void	rotate_till_min(t_stack *s);
int		max_from_bottom(t_stack *b);
int		max_from_top(t_stack *b);
int		range_from_bottom(t_stack *a, int min, int max);
int		range_from_top(t_stack *a, int min, int max);

/**************** utils ****************/
void	print_error(void);
void	ft_exit(char *str);

#endif
