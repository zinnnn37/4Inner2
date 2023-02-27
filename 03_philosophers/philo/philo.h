/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:03:26 by minjinki          #+#    #+#             */
/*   Updated: 2023/02/27 15:42:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>

# define SUCCESS 0
# define FAILURE 1
# define TRUE 1
# define FALSE 0

typedef struct s_philo
{
}	t_philo;

/*************** utils.c ***************/
void	ft_putnbr(int n);
void	ft_putstr(const char *s);
int		ft_strlen(const char *s);
int		print_error(char *s);

#endif