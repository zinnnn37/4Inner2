/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:27:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/23 16:10:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

template <typename T>
int	easyfind( T &t, int n )
{
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), n);

	if (it == t.end())
		throw "Occurence Not Found";
	
	return (std::distance(t.begin(), it));
}

#endif