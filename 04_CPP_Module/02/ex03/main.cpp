/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:24:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 21:36:19 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main( void )
{
	Point	a( 0.0, 0.0 );
	Point	b( 5.0, 0.0 );
	Point	c( 0.0, 5.0 );
	Point	p( 1.0, 0.0 );

	std::cout << (bsp(a, b, c, p) ? "Point is in the Triangle"
		: "Point is out of Triangle") << std::endl;

	return 0;
}

/*
// in
	Point	a( 0.0, 0.0 );
	Point	b( 5.0, 0.0 );
	Point	c( 0.0, 5.0 );
	Point	p( 1.0, 1.0 );

// out
	Point	a( 3.2f, 5.6f );
	Point	b( -1.2f, -2.4f );
	Point	c( 7.2f, 1.9f );
	Point	p( -0.2f, 4.8f );

	Point	a( 3.2f, 5.6f );
	Point	b( -1.2f, -2.4f );
	Point	c( 7.2f, 1.9f );
	Point	p( 7.2f, 1.9f );	// 꼭짓점에 위치
*/