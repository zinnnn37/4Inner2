/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:17:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/23 18:45:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "usage: ./bitcoin [input_file]" << std::endl;
		return (1);
	}

	try
	{
		BitcoinExchange	be(av[1]);
	}
	catch (const char *e)
	{
		std::cout << "Error: " << e << std::endl;
		return (1);
	}
	return (0);
}