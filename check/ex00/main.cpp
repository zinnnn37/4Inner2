/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:17:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/26 19:23:02 by minjinki         ###   ########.fr       */
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

	BitcoinExchange	be(av[1]);

	be.exec();

	return (0);
}