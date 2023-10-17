/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:27:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/17 13:43:26 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <deque>

class	NotFoundException : public std::exception
{
	public:
		virtual const char	*what() const throw()
		{
			return ("Occurence Not Found");
		}
};

template <typename T>
int	easyfind( T &t, int n )
{
	typename T::iterator it;

	it = std::find(t.begin(), t.end(), n);

	if (it == t.end())
		throw NotFoundException();
	
	return (it - t.begin());
}

#endif