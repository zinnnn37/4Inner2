/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:40:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/17 08:58:04 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter( T *arr, unsigned int len, void( *f )( T & ) )
{
	for (unsigned int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	iter( const T *arr, unsigned int len, void( *f )( const T & ) )
{
	for (unsigned int i = 0; i < len; i++)
		f(arr[i]);
}

template <typename T>
void	add( T &t )
{
	t += 1;
}

template <typename T>
void	print( const T &t )
{
	std::cout << t << " ";
}

#endif