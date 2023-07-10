/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:45:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/10 11:10:32 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	abs(Fixed f)
{
	float	x;

	x = f.toFloat();
	
	return (x >= 0 ? x : -x);
}

float	get_area( Point const a, Point const b, Point const c )
{
	float	area;
	Fixed	tmp;

	tmp = (a.getX() * b.getY() + b.getX() * c.getY() + c.getX() * a.getY())
		- (b.getX() * a.getY() + c.getX() * b.getY() + a.getX() * c.getY());
	
	area = 0.5 * abs(tmp);

	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float	s1;
	float	s2;
	float	s3;

	s1 = get_area(a, b, point);
	s2 = get_area(b, c, point);
	s3 = get_area(a, c, point);

	std::cout << s1 << ", " << s2 << ", " << s3 << ", " << get_area(a, b, c) << std::endl;
	std::cout << (s1 + s2 + s3) << ", " << get_area(a, b, c) << std::endl;
	// rm above

	if (s1 == 0.00000000 || s2 == 0.00000000 || s3 == 0.00000000)
		return false;
	
	if (s1 + s2 + s3 == get_area(a, b, c))
		return true;

	return false;
}