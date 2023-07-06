/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/06 12:36:59 by minjinki         ###   ########.fr       */
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

bool	Fixed::operator>( const Fixed& fixed ) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<( const Fixed& fixed ) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=( const Fixed& fixed ) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=( const Fixed& fixed ) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==( const Fixed& fixed ) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=( const Fixed& fixed ) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+( const Fixed& fixed )
{
	Fixed	res( this->toFloat() + fixed.toFloat() );

	return res;
}

Fixed	Fixed::operator-( const Fixed& fixed )
{
	Fixed	res( this->toFloat() - fixed.toFloat() );

	return res;
}

Fixed	Fixed::operator*( const Fixed& fixed )
{
	Fixed	res( this->toFloat() * fixed.toFloat() );

	return res;
}

Fixed	Fixed::operator/( const Fixed& fixed )
{
	try
	{
		if (fixed.toFloat() == 0)
			throw "Division by Zero.";
	}
	catch(const char* str)
	{
		std::cout << str << std::endl;
		std::exit(1);
	}
	
	Fixed	res( this->toFloat() / fixed.toFloat() );	

	return res;
}

Fixed&	Fixed::operator++( void )
{
	int	tmp;

	tmp = this->getRawBits();
	this->setRawBits(++tmp);	// ε로부터 증가 || 감소 > rawbit 바로 ++하기?

	return *this;
}

const Fixed	Fixed::operator++( int ) // const?
{
	int		tmp;
	Fixed	res(*this);

	tmp = this->getRawBits();
	this->setRawBits(++tmp);

	return res;
}

Fixed&	Fixed::operator--( void )
{
	int	tmp;

	tmp = this->getRawBits();
	this->setRawBits(--tmp);

	return *this;
}

const Fixed	Fixed::operator--( int )
{
	int		tmp;
	Fixed	res(*this);

	tmp = this->getRawBits();
	this->setRawBits(--tmp);

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

Fixed	Fixed::min( Fixed &f1, Fixed &f2 )
{
	return ( f1 < f2 ? f1 : f2 );
}

const Fixed	Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	return ( f1 < f2 ? f1 : f2 );
}

Fixed	Fixed::max( Fixed &f1, Fixed &f2 )
{
	return ( f1 > f2 ? f1 : f2 );
}

const Fixed	Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	return ( f1 > f2 ? f1 : f2 );
}

// funcs
std::ostream&	operator<<( std::ostream &out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return (out);
}