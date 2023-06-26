/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:51:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 19:17:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_fixed;
		static const int	_bit = 8;

	public:
		Fixed();
		Fixed( int fixed );
		Fixed( float fixed );
		Fixed( const Fixed& fixed );
		~Fixed();

		Fixed&	operator=( const Fixed& fixed );

		bool	operator>( const Fixed& fixed ) const;
		bool	operator<( const Fixed& fixed ) const;
		bool	operator>=( const Fixed& fixed ) const;
		bool	operator<=( const Fixed& fixed ) const;
		bool	operator==( const Fixed& fixed ) const;
		bool	operator!=( const Fixed& fixed ) const;

		Fixed	operator+( const Fixed& fixed );
		Fixed	operator-( const Fixed& fixed );
		Fixed	operator*( const Fixed& fixed );
		Fixed	operator/( const Fixed& fixed );

		Fixed&	operator++( void );	// 전위연산자
		Fixed	operator++( int );	// 후위연산자
		Fixed&	operator--( void );
		Fixed	operator--( int );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		min( Fixed &f1, Fixed &f2 );
		static const Fixed	min( const Fixed &f1, const Fixed &f2 );
		static Fixed		max( Fixed &f1, Fixed &f2 );
		static const Fixed	max( const Fixed &f1, const Fixed &f2 );
		// static 멤버 함수는 객체별로 생성되는 게 아니라 모든 객체가 공유함
};

std::ostream&	operator<<( std::ostream &out, const Fixed& fixed );

#endif