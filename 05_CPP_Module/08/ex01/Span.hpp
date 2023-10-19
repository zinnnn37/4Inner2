/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/19 11:54:07 by minjinki         ###   ########.fr       */
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

	public:
		Span( unsigned int N );
		Span( const Span & src );
		~Span();

		Span	&operator=( const Span & s );

		void			addNumber( int n );
		int				shortestSpan();
		int				longestSpan();

		unsigned int	getN() const;
		unsigned int	size() const;

		void			print() const;
};

void	red();
void	blue();
void	reset();

#endif