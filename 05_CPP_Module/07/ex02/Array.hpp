/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:06:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/18 10:28:22 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>

#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

template <typename T>
class	Array
{
	private:
		T				*_arr;
		unsigned int	_size;

	public:
		Array<T>( void ) : _size(0)
		{
			this->_arr = new T[0];
		}

		Array<T>( unsigned int n ) : _size(n)
		{
			this->_arr = new T[n];
		}

		Array<T>( Array<T> const &arr )
		{
			this->_arr = NULL;
			*this = arr;
		}

		~Array<T>()
		{
			if ( this->_arr )
				delete[] this->_arr;
		}

		Array<T>	&operator=( const Array<T> &arr )
		{
			if (this == &arr)
				return (*this);

			if (this->_arr)
			{
				delete[] this->_arr;
				this->_arr = NULL;
			}

			this->_size = arr.size();
			this->_arr = new T[this->_size];

			for (unsigned int i = 0; i < this->_size; i++)
				this->_arr[i] = arr._arr[i];

			return (*this);
		}

		T		&operator[]( unsigned int n )
		{
			if (n >= this->_size)
				throw std::exception();
			return (this->_arr[n]);
		}

		unsigned int	size() const
		{
			return (this->_size);
		}
};

void	blue()
{
	std::cout << BLUE;
}

void	reset()
{
	std::cout << RESET;
}

void	red()
{
	std::cout << RED;
}

#endif