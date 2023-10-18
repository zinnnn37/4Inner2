/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:40:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/18 10:04:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	append( std::string &a )
{
	a.append("_append");
}

int	main(void)
{
	std::cout << "----------- int test ------------\n\n";

	int	arr[5] = { 1, 2, 3, 4, 5 };

	iter(arr, 5, print);
	std::cout << std::endl;

	iter(arr, 5, add);

	iter(arr, 5, print);
	std::cout << std::endl;

	std::cout << "\n----------- char test -----------\n\n";

	char	c[5] = { 'a', 'b', 'c', 'd', 'e' };

	iter(c, 5, print);
	std::cout << std::endl;

	iter(c, 5, add);

	iter(c, 5, print);
	std::cout << std::endl << std::endl;

	return (0);
}