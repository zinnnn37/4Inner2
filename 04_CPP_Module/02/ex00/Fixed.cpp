/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:00:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/23 18:47:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
	: _fixed(0)	// 생성자 내 할당보다 이게 낫다고 마소가 그랫음..
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& fixed )
{
	std::cout << "Copy constructor called" << std::endl;
	
	*this = fixed;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=( const Fixed& fixed )
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this == &fixed)
		return (*this);
	
	this->setRawBits( fixed.getRawBits() );
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (this->_fixed);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}