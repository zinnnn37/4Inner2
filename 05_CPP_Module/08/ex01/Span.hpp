/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/23 16:02:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <deque>
#include <climits>

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"

class	Span
{
	private:
		unsigned int	_N;
		std::deque<int>	_dq;

		Span();

		unsigned int	_getN() const;
		unsigned int	_size() const;

	public:
		Span( unsigned int N );
		Span( const Span & src );
		~Span();

		Span	&operator=( const Span & s );

		void			addNumber( int n );
		int				shortestSpan();
		int				longestSpan();

		void			print() const;
};

void	red();
void	blue();
void	reset();

#endif