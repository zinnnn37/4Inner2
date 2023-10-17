/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:02:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/17 14:36:55 by minjinki         ###   ########.fr       */
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
	if (this->_vec.size() == _N)
		throw FullException();

	if (find(this->_vec.begin(), this->_vec.end(), this->_vec.size())
		== this->_vec.end())
		this->_vec.push_back(n);
}

int	Span::shortestSpan()
{
	if (this->_vec.size() <= 1)
		throw CannotSpanException();

	int					shortest = INT_MAX;
	std::vector<int>	tmp(_vec);

	std::sort(tmp.begin(), tmp.end());

	for (unsigned int i = 0; i < tmp.size() - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < shortest)
			shortest = tmp[i + 1] - tmp[i];
	}

	return (shortest);
}

int	Span::longestSpan()
{
	if (this->_vec.size() <= 1)
		throw CannotSpanException();
	
	int	min, max;

	min = *std::min_element(this->_vec.begin(), this->_vec.end());
	max = *std::max_element(this->_vec.begin(), this->_vec.end());

	return (max - min);
}
