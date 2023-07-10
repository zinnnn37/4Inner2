/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:51:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/10 12:22:56 by minjinki         ###   ########.fr       */
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

		Fixed&		operator++( void );
		const Fixed	operator++( int );
		Fixed&		operator--( void );
		const Fixed	operator--( int );
		
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		min( Fixed &f1, Fixed &f2 );
		static const Fixed	min( const Fixed &f1, const Fixed &f2 );
		static Fixed		max( Fixed &f1, Fixed &f2 );
		static const Fixed	max( const Fixed &f1, const Fixed &f2 );
};

std::ostream&	operator<<( std::ostream &out, const Fixed& fixed );

#endif
