/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:51:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/23 18:56:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>	// roundf

class	Fixed
{
	private:
		int					_fixed;
		static const int	_bit = 8;

	public:
		Fixed();
		Fixed( const Fixed& fixed );
		~Fixed();
		Fixed& operator=( const Fixed& fixed );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed& operator<<( Fixed& fixed );
};

#endif