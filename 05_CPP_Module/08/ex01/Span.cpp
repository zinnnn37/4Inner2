/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:02:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/19 11:54:50 by minjinki         ###   ########.fr       */
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
		_dq.assign(s._dq.begin(), s._dq.end());
	}
	return (*this);
}

void	Span::addNumber( int n )
{
	if (this->_dq.size() == _N)
		throw "Span is full";

	if (find(this->_dq.begin(), this->_dq.end(), n)
		== this->_dq.end())
		this->_dq.push_back(n);
}

int	Span::shortestSpan()
{
	if (this->size() <= 1)
		throw "Too few arguments to span";

	int				shortest = INT_MAX;
	std::deque<int>	tmp(_dq);

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
	if (this->size() <= 1)
		throw "Too few arguments to span";
	
	int	min, max;

	min = *std::min_element(this->_dq.begin(), this->_dq.end());
	max = *std::max_element(this->_dq.begin(), this->_dq.end());

	return (max - min);
}

unsigned int	Span::getN() const
{
	return (this->_N);
}

unsigned int	Span::size() const
{
	return (this->_dq.size());
}

void	Span::print() const
{
	for (unsigned int i = 0; i < this->size(); i++)
		std::cout << this->_dq[i] << " ";
	std::cout << std::endl;
}

//const char	*Span::FullException::what() const throw()
//{
//	red();
//	return ("Span is full");
//}

//const char	*Span::CannotSpanException::what() const throw()
//{
//	red();
//	return ("Too few arguments to span");
//}

void	red()
{
	std::cout << RED;
}

void	blue()
{
	std::cout << BLUE;
}

void	reset()
{
	std::cout << RESET;
}
