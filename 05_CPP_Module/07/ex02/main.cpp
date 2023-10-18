/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:41 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/18 11:11:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	leaks()
{
	system("leaks Array");
}

int	main(void)
{
	atexit(leaks);

	Array<int>	arr1(5);
	Array<char> arr2(5);

	for (int i = 0; i < static_cast<int>(arr1.size()); i++)
	{
		arr1[i] = i;
		arr2[i] = i + 'A';
	}

	std::cout << "\narr1: " << arr1.size() << std::endl;
	std::cout << "arr2: " << arr2.size() << '\n' << std::endl;

	for (int i = 0; i < static_cast<int>(arr1.size()); i++)
		std::cout << "arr1: " << arr1[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < static_cast<int>(arr2.size()); i++)
		std::cout << "arr2: " << arr2[i] << " ";
	std::cout << std::endl;

	blue();
	std::cout << "\n========== Copy Assignment Test ==========\n" << std::endl;
	reset();

	Array<int> test = arr1;

	for (int i = 0; i < static_cast<int>(test.size()); i++)
		std::cout << "arr: " << arr1[i] << ", test: " << test[i] << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < static_cast<int>(test.size()); i++)
		test[i] += 1;

	for (int i = 0; i < static_cast<int>(test.size()); i++)
		std::cout << "arr: " << arr1[i] << ", test: " << test[i] << std::endl;
	std::cout << std::endl;

	blue();
	std::cout << "========== Copy Constructor Test =========\n" << std::endl;
	reset();

	Array<int> test2(test);
	
	for (int i = 0; i < static_cast<int>(test2.size()); i++)
		std::cout << "test: " << test[i] << ", test2: " << test2[i] << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < static_cast<int>(test2.size()); i++)
		test2[i] += 1;

	for (int i = 0; i < static_cast<int>(test2.size()); i++)
		std::cout << "test: " << test[i] << ", test2: " << test2[i] << std::endl;
	std::cout << std::endl;

	blue();
	std::cout << "============= Exception Test =============\n" << std::endl;
	reset();

	try
	{
		std::cout << "----------- Index Out of Bounds ----------\n" << std::endl;
		std::cout << arr1[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		reset();
	}

	// negative
	try
	{
		std::cout << "\n------------- Negative Index -------------\n" << std::endl;
		std::cout << arr1[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		reset();
	}

	std::cout << std::endl;

	return (0);
}