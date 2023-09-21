/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:47:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/21 12:14:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern &intern )
{
	(void)intern;
	*this = intern;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=( const Intern &intern )
{
	(void)intern;
	return (*this);
}

AForm*	Intern::makeForm( std::string form, std::string target )
{
	int			pos;
	std::string	check;
	AForm*		( Intern::*f[3] )( std::string )
				= { &Intern::makeShrubberyCreationForm,
				&Intern::makeRobotomyRequestForm,
				&Intern::makePresidentialPardonForm };

	check = "0shrubbery creation1robotomy request2presidential pardon";
	pos = check[check.find(form) - 1] - '0';

	if (check.find(form) == std::string::npos)
		throw Intern::InvalidFormException();
	else
		return ((this->*f[pos])(target));
}

AForm*	Intern::makeShrubberyCreationForm( std::string target )
{
	green();
	std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
	reset();
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeRobotomyRequestForm( std::string target )
{
	green();
	std::cout << "Intern creates RobotomyRequestForm" << std::endl;
	reset();
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::makePresidentialPardonForm( std::string target )
{
	green();
	std::cout << "Intern creates PresidentialPardonForm" << std::endl;
	reset();
	return (new PresidentialPardonForm(target));
}

const char*	Intern::InvalidFormException::what() const throw()
{
	red();
	return ("Error: Invalid form name");
}
