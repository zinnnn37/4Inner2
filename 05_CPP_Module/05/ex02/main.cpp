/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 17:25:30 by minjinki         ###   ########.fr       */
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
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}