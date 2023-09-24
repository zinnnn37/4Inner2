/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/24 15:16:21 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	// ShrubberyCrationForm
	try
	{
		Bureaucrat				b1("b1", 1);
		Bureaucrat				b2("b2", 137);
		Bureaucrat				b3("b3", 145);
		ShrubberyCreationForm	sf("shrubbery");

		std::cout << sf << std::endl;

		b1.signForm(sf);
		b1.executeForm(sf);
		std::cout << std::endl;

		sf.setSigned(false);

		b2.signForm(sf);
		b2.executeForm(sf);
		std::cout << std::endl;

		sf.setSigned(false);

		b1.signForm(sf);
		b3.executeForm(sf);
		std::cout << std::endl;
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << '\n';
	}

	reset();

	//RobotomyRequestForm
	try
	{
		Bureaucrat				b1("b1", 1);
		Bureaucrat				b2("b2", 72);
		RobotomyRequestForm		rf("robotomy");

		std::cout << rf << std::endl;

		b1.signForm(rf);
		b1.executeForm(rf);
		std::cout << std::endl;

		rf.setSigned(false);

		b1.signForm(rf);
		b2.executeForm(rf);
		std::cout << std::endl;
	}
	catch ( const std::exception &e )
	{
		std::cerr << e.what() << '\n';
	}

	reset();

	// PresidentialPardonForm
	try
	{
		Bureaucrat				b1("b1", 5);
		Bureaucrat				b2("b2", 26);
		PresidentialPardonForm	pf("president");

		std::cout << pf << std::endl;

		b1.signForm(pf);
		b1.executeForm(pf);
		std::cout << std::endl;

		pf.setSigned(false);

		b1.signForm(pf);
		b2.executeForm(pf);
		std::cout << std::endl;
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}