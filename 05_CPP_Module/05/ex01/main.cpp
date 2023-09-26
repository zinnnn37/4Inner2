/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/26 13:41:02 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("b", 1);
		Form		f("f", 1, 1);

		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch ( std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat	b("b", 50);
		Form		f("f", 49, 51);

		//b.increaseGrade();
		//b.increaseGrade();
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}