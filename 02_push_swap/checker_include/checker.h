/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:01:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/06 13:30:00 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"

# define FAILURE 1
# define SUCCESS 0
# define DUP -1

typedef int	t_bool;

typedef struct s_data
{
	int				data;
	struct s_data	*prev;
	struct s_data	*next;
}	t_data;

typedef struct s_stack
{
	t_data	*top;
	t_data	*bottom;
	int		size;
}	t_stack;

/**************** do_op ****************/
void	do_op(t_stack *a, t_stack *b);

/*************** command ***************/
void	sn(t_stack *s);
void	ss(t_stack *a, t_stack *b);
void	rn(t_stack *s);
void	rr(t_stack *a, t_stack *b);
void	rrn(t_stack *s);
void	rrr(t_stack *a, t_stack *b);
void	pn(t_stack *from, t_stack *to);

/**************** parse ****************/
void	get_numbers(int ac, char **av, t_stack *s);

/**************** stack ****************/
void	create_and_add_node(t_stack *s, int data);
t_bool	is_empty(t_stack *b);
t_bool	is_ordered_not_dup(t_stack *a);
void	print_nodes(t_stack *a, t_stack *b);

/**************** utils ****************/
void	ft_exit(void);
void	print_error(void);

#endif