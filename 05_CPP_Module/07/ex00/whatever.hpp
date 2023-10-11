/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:09 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 15:38:54 by minjinki         ###   ########.fr       */
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
T	min( const T &a, const T &b )
{
	return (a < b ? a : b);
}

template <typename T>
T	max( const T &a, const T &b )
{
	return (a > b ? a : b);
}

#endif