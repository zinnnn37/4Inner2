/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 10:29:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat				b1("b1", 1);
		Bureaucrat				b2("b2", 137);
		Bureaucrat				b3("b3", 145);
		ShrubberyCreationForm	f("sf");

		std::cout << f << std::endl;

		b1.signForm(f);
		b1.executeForm(f);
		std::cout << std::endl;

		f.setSigned(false);

		b2.signForm(f);
		b2.executeForm(f);
		std::cout << std::endl;

		f.setSigned(false);

		b3.signForm(f);
		b3.executeForm(f);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}