/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:16:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/09 21:39:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point( const float x, const float y );
		Point( const Point& point );
		~Point();
		
		Point&	operator=( const Point& point );

		Fixed	getX() const;
		Fixed	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif