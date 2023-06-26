/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 18:40:16 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
	: _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int fixed )
	: _fixed(fixed << this->_bit)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( float fixed )
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits( static_cast<int>(std::roundf(fixed * (1 << this->_bit))) );
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
	std::cout << "Assignment operator called" << std::endl;

	if (this == &fixed)
		return (*this);
	
	this->setRawBits( fixed.getRawBits() );
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed >> this->_bit);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->_bit));
}

std::ostream&	operator<<( std::ostream &out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return (out);
}