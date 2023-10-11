/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 16:14:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <excption>

template <typename T>
class	Array
{
	private:
		T				*arr;
		unsigned int	len;

	public:
		Array();
		Array( unsigned int n );
		Array( Array const &arr );
		~Array();

		Array	&operator=( const Array &arr );
		T		&operator[]( unsigned int n );

		unsigned int	size() const;

		class	IndexOutOfRangeException : public std::exception
		{
			public:
				const char	*what() const throw();
		}
}

#endif