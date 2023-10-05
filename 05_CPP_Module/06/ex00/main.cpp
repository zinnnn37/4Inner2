/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:56:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/05 12:39:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main( int ac, char **av )
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./convert value" << std::endl;
		return 1;
	}
	//ScalarConverter::convert(av[1]);
	(void)av;
	return 0;
}
