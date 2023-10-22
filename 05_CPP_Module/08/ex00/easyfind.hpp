/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:27:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/19 12:07:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <deque>

template <typename T>
int	easyfind( T &t, int n )
{
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), n);

	if (it == t.end())
		throw "Occurence Not Found";
	
	return (it - t.begin());
	// distance
}

#endif