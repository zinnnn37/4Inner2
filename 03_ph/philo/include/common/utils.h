/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hroussea <hroussea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:17:48 by hroussea          #+#    #+#             */
/*   Updated: 2021/12/23 15:12:09 by hroussea         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <common/types.h>
# include <sys/time.h>
# include <stdlib.h>

t_usize	get_now(void);
t_bool	ft_satoi(t_i32 *ret, const t_string str);
void	ft_usleep(t_u64 time);

#endif
