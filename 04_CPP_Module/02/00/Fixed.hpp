/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:00:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/23 18:29:44 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif