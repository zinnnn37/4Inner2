/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:30:19 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/16 19:35:02 by marousta         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <sys/types.h>

typedef signed char			t_i8;
typedef unsigned char		t_u8;
typedef signed short		t_i16;
typedef unsigned short		t_u16;
typedef signed int			t_i32;
typedef unsigned int		t_u32;
typedef signed long			t_i64;
typedef unsigned long		t_u64;
typedef char*				t_string;

typedef _Bool				t_bool;

typedef float				t_f32;
typedef double				t_f64;

typedef ssize_t				t_isize;
typedef size_t				t_usize;

# define TRUE				1
# define FALSE				0

#endif
