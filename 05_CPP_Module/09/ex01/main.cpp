/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:25:34 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 18:33:47 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN \"RPN operations\"" << std::endl;
		return 1;
	}

	RPN	rpn(av[1]);

	return 0;
}