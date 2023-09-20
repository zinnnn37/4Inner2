/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/20 11:49:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <stdlib.h>

void	leaks(void)
{
	system("leaks Intern");
}

int	main()
{
	atexit(leaks);

	Intern	someRandomIntern;
	AForm	*rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	Bureaucrat	b("b", 1);

	b.signForm(*rrf);
	b.executeForm(*rrf);

	delete rrf;

	std::cout << std::endl;

	try
	{
		AForm	*wrong;

		wrong = someRandomIntern.makeForm("wrong", "Bender");
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}