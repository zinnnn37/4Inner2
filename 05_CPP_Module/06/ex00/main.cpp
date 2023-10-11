/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:56:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 13:06:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int ac, char **av )
{
	if (ac == 2)
	{
		try
		{
			ScalarConverter	convert(av[1]);
		}
		catch ( const std::exception& e )
		{
			std::cerr << e.what() << std::endl;
		}

		std::cout << "----------------------------------" << std::endl;
		try
		{
			ScalarConverter::setInput("42");
			ScalarConverter::convert();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		
		return (0);
	}
	std::cout << "Usage: ./converter param" << std::endl;
	return (1);
}