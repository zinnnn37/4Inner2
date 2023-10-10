/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:56:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/10 16:42:24 by minjinki         ###   ########.fr       */
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
		return (0);
	}
	std::cout << "Usage: ./converter param" << std::endl;
	return (1);
}