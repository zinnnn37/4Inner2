/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:01:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/01/31 15:05:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FAILURE 1
# define SUCCESS 0

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

/*************** command ***************/
int		sn(t_stack *s, char *str);
int		rn(t_stack *s, char *str);
int		rrn(t_stack *s, char *str);
void	pn(t_stack *from, t_stack *to, char *str);

#endif