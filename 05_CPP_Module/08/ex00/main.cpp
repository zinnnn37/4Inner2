/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:27:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/19 11:53:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>

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
		std::cout << "res: " << idx << std::endl;
		std::cout << "deque[res]: " << deque[idx] << std::endl;

		std::cout << "\nfind 5 in deque" << std::endl;
		idx = easyfind(deque, 5);
		std::cout << "res: " << idx << std::endl;
		std::cout << "deque[res]: " << deque[idx] << std::endl;
	}
	catch( const char *e )
	{
		std::cerr << e << '\n' << std::endl;
	}

	std::cout << "=========== char test ============\n" << std::endl;

	std::deque<char>	deque2;

	for (int i = 0; i < 5; i++)
		deque2.push_back(i + 'a');

	try
	{
		std::cout << "find e in deque" << std::endl;
		int	idx = easyfind(deque2, 'e');
		std::cout << "res: " << idx << std::endl;
		std::cout << "deque[res]: " << deque2[idx] << std::endl;

		std::cout << "\nfind v in deque" << std::endl;
		idx = easyfind(deque2, 'v');
		std::cout << "res: " << idx << std::endl;
		std::cout << "deque[res]: " << deque2[idx] << std::endl;
	}
	catch(const char *e)
	{
		std::cerr << e << '\n' << std::endl;
	}
	

	return 0;
}
