/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:09 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/18 11:05:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void	swap( T &a, T &b )
{
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T	min( T &a, T &b )
{
	return (a < b ? a : b);
}

template <typename T>
T	max( T &a, T &b )
{
	return (a > b ? a : b);
}

#endif