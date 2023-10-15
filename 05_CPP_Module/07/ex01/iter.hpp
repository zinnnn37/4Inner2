/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:40:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/15 11:14:37 by minjinki         ###   ########.fr       */
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

// const도 만들어야 함

#endif