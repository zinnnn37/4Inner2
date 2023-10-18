/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:05:41 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/18 10:11:35 by minjinki         ###   ########.fr       */
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

	Array<int>	arr(5);

	for (int i = 0; i < static_cast<int>(arr.size()); i++)
		arr[i] = i;

	std::cout << "arr: " << arr.size() << "\n" << std::endl;

	for (int i = 0; i < static_cast<int>(arr.size()); i++)
		std::cout << "arr: " << arr[i] << std::endl;

	blue();
	std::cout << "\n========== Copy Assignment Test ==========\n" << std::endl;
	reset();

	Array<int> test = arr;

	for (int i = 0; i < static_cast<int>(test.size()); i++)
		std::cout << "arr: " << arr[i] << ", test: " << test[i] << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < static_cast<int>(test.size()); i++)
		test[i] += 1;

	for (int i = 0; i < static_cast<int>(test.size()); i++)
		std::cout << "arr: " << arr[i] << ", test: " << test[i] << std::endl;
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
		std::cout << arr[5] << std::endl;
	}
	catch (std::exception &e)
	{
		red();
		std::cout << e.what() << std::endl;
		reset();
	}

	// negative
	try
	{
		std::cout << "\n------------- Negative Index -------------\n" << std::endl;
		std::cout << arr[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		red();
		std::cout << e.what() << std::endl;
		reset();
	}

	std::cout << std::endl;

	return (0);
}