/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:17:11 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/09 21:57:53 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	: _x(0), _y(0)
{
}

Point::Point( const float x, const float y )
	: _x(x), _y(y)
{
}

Point::Point( const Point& point )
{
	if (this != &point)
		*this = point;
}

Point::~Point()
{
}

Point&	Point::operator=( const Point& point )
{// const 속성을 잠시 없애주는 const_cast, 포인터간 사용 가능
	Fixed	*px	= const_cast<Fixed *>(&(this->_x));
	Fixed	*py	= const_cast<Fixed *>(&(this->_y));
	
	if (this == &point)
		return *this;

	*px = point._x;
	*py = point._y;

	return *this;
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}


