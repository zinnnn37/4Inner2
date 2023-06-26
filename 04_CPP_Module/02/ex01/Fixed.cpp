/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:44:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 17:39:35 by minjinki         ###   ########.fr       */
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
	// 고정을 정수로
	return (this->_fixed >> this->_bit);
}

float	Fixed::toFloat( void ) const
{
	// 고정을 부동으로
	return (static_cast<float>(this->getRawBits()) / (1 << this->_bit));
}

std::ostream&	operator<<( std::ostream &out, const Fixed& fixed )
{
	out << fixed.toFloat();
	return (out);
	// cout << a << b << c;
	// cout << a 후 cout << b << c가 남은 형태여야 함
	// 따라서 out을 마지막에 리턴해줘야 함
	// 이 때 매개변수로 받은 레퍼런스를 그대로 반환 > 맨 처음에 사용된 out값이 마지막까지 남음
}