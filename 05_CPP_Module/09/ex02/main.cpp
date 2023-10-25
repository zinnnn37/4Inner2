/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:05:27 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/25 11:14:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Usage: ./PmergeMe [numbers]" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe	pm(ac, av);
	}
	catch ( const char *e )
	{
		std::cerr << e << std::endl;
		return 1;
	}

	return 0;
}
