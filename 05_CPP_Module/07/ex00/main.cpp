/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:30:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 15:39:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	int	a = 2;
	int	b = 3;

	std::cout << "----------- int test ------------\n" << std::endl;

	std::cout << "ori: a = " << a << ", b = " << b << std::endl;

	::swap( a, b );

	std::cout << "swp: a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "\n---------- string test ----------\n" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "ori: c = " << c << ", d = " << d << std::endl;

	::swap(c, d);

	std::cout << "swp: c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return (0);
}