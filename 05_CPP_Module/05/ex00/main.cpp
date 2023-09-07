/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:59:49 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/07 12:09:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("minjinki", 1);

		std::cout << b << std::endl;

		b.increase_grade();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n-----------------------------------\n" << std::endl;

	try
	{
		Bureaucrat	b("minjinki", 149);

		std::cout << b << std::endl;

		b.decrease_grade();
		std::cout << b << std::endl;

		b.decrease_grade();
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
