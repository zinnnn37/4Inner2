/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MJKim <zinnnn37@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:31:36 by MJKim             #+#    #+#             */
/*   Updated: 2023/03/08 09:31:36 by MJKim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum e_type
{
	T_NULL,
	T_STR,
	T_PIPE,
	T_REDI,
	T_DOUBLE,
	T_SINGLE
}	t_type;

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

#endif