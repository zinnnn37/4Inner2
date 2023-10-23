/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:27:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/23 16:10:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <vector>

int	main()
{
	std::cout << "========== integer test ==========\n" << std::endl;

	std::deque<int>	deque;

	for (int i = 0; i < 5; i++)
		deque.push_back(i);
	
	try
	{
		std::cout << "find 3 in deque" << std::endl;
		int	idx = easyfind(deque, 3);
		std::cout << "idx: " << idx << std::endl;
		std::cout << "deque[res]: " << deque[idx] << std::endl;

		std::cout << "\nfind 5 in deque" << std::endl;
		idx = easyfind(deque, 5);
		std::cout << "idx: " << idx << std::endl;
		std::cout << "deque[res]: " << deque[idx] << std::endl;
	}
	catch( const char *e )
	{
		std::cerr << e << '\n' << std::endl;
	}

	std::cout << "=========== char test ============\n" << std::endl;

	std::vector<char>	vec;

	for (int i = 0; i < 5; i++)
		vec.push_back(i + 'a');

	try
	{
		std::cout << "find e in vector" << std::endl;
		int	idx = easyfind(vec, 'e');
		std::cout << "idx: " << idx << std::endl;
		std::cout << "vector[res]: " << vec[idx] << std::endl;

		std::cout << "\nfind v in vector" << std::endl;
		idx = easyfind(vec, 'v');
		std::cout << "idx: " << idx << std::endl;
		std::cout << "vector[res]: " << vec[idx] << std::endl;
	}
	catch(const char *e)
	{
		std::cerr << e << '\n' << std::endl;
	}

	return 0;
}
