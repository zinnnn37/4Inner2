/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 18:51:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructor && destructor
Fixed::Fixed( void )
	: _fixed(0)
{
}

Fixed::Fixed( int fixed )
	: _fixed(fixed << this->_bit)
{
}

Fixed::Fixed( float fixed )
{
	this->setRawBits( static_cast<int>(std::roundf(fixed * (1 << this->_bit))) );
}

Fixed::Fixed( const Fixed& fixed )
{
	*this = fixed;
}

Fixed::~Fixed( void )
{
}

// overloading
Fixed&	Fixed::operator=( const Fixed& fixed )
{
	if (this == &fixed)
		return (*this);
	
	this->setRawBits( fixed.getRawBits() );
	return (*this);
}

bool	Fixed::operator>( const Fixed& fixed )
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<( const Fixed& fixed )
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=( const Fixed& fixed )
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=( const Fixed& fixed )
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==( const Fixed& fixed )
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=( const Fixed& fixed )
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+( const Fixed& fixed );
{
	Fixed	res( this->toFloat() + fixed.toFloat() );

	return res;
}

Fixed	Fixed::operator-( const Fixed& fixed );
{
	Fixed	res( this->toFloat() - fixed.toFloat() );

	return res;
}

Fixed	Fixed::operator*( const Fixed& fixed );
{
	Fixed	res( this->toFloat() * fixed.toFloat() );

	return res;
}

Fixed	Fixed::operator/( const Fixed& fixed );
{
	Fixed	res( this->toFloat() / fixed.toFloat() );

	return res;
}

// getter && setter
int	Fixed::getRawBits( void ) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

// member funcs
int	Fixed::toInt( void ) const
{
	return (this->_fixed >> this->_bit);
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << this->_bit));
}

// funcs
std::ostream&	operator<<( std::ostream &out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return (out);
}