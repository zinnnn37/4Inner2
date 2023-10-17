/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:02:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/17 14:12:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {}

Span::Span( unsigned int N ) : _N(N) {}

Span::Span( const Span &s )
{
	*this = s;
}

Span::~Span() {}

Span	&Span::operator=( const Span &s )
{
	if (this != &s)
	{
		_N = s._N;
		_vec.assign(s._vec.begin(), s._vec.end());
	}
	return (*this);
}

void	Span::addNumber( int n )
{
	if (_vec.size() == _N)
		throw FullException();

	_vec.push_back(n);
}
