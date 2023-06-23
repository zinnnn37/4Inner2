/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:59:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/23 16:04:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	h;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter keyword" << std::endl;
		return (1);
	}
	
	h.complain(av[1]);

	return (0);
}