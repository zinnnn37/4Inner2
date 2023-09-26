/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:01:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/26 13:43:54 by minjinki         ###   ########.fr       */
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

	std::cout << *rrf << std::endl;

	Bureaucrat	b("b", 1);

	b.signForm(*rrf);
	b.executeForm(*rrf);

	delete rrf;

	std::cout << std::endl;

	try
	{
		AForm	*wrong;

		wrong = someRandomIntern.makeForm("wrong form", "Bender");
		(void)wrong;
	}
	catch ( const std::exception& e )
	{
		std::cerr << e.what() << RESET << '\n';
	}

	return 0;
}