/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:35:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 10:29:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define FAILURE 1
# define SUCCESS 0

typedef struct s_data
{
	int				data;
	struct t_data	*prev;
	struct t_data	*next;
}	t_data;

typedef struct s_stack
{
	struct t_data	*top;
	struct t_data	*bottom;
	int				size;
}	t_stack;

/*************** command ***************/
void	sn(t_stack s, char *str);

/************* hard coding *************/
void	sort_two(t_stack a);

void	ft_putstr(char *str);
void	print_error(char *str);

#endif
