/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:40:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 16:05:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	add( int &a )
{
	a += 1;
}

void	append( std::string &a )
{
	a.append("_append");
}

int	main(void)
{
	std::cout << "----------- int test ------------\n\n";

	int	arr[5] = { 1, 2, 3, 4, 5 };

	for ( int i = 0; i < 5; i++ )
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	iter(arr, 5, add);

	for ( int i = 0; i < 5; i++ )
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "\n---------- string test ----------\n\n";

	std::string	str[5] = { "a", "b", "c", "d", "e" };

	for (int i = 0; i < 5; i++ )
		std::cout << str[i] << " ";
	std::cout << std::endl;

	iter(str, 5, append);

	for (int i = 0; i < 5; i++ )
		std::cout << str[i] << " ";
	std::cout << std::endl << std::endl;

	return (0);
}