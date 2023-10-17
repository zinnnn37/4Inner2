/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:02:35 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/17 14:11:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class	Span
{
	private:
		unsigned int		_N;
		std::vector<int>	_vec;

		Span();

	public:
		Span( unsigned int N );
		Span( const Span & src );
		~Span();

		Span	&operator=( const Span & s );

		void	addNumber( int n );
		int		shortestSpan();
		int		longestSpan();

		class	FullException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	CannotSpanException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
}

#endif