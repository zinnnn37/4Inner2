/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:47:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/07 14:05:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern( const Intern &intern )
{
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
	std::string	check[3]
				= {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm*		( Intern::*f[3] )( std::string )
				= { &Intern::makeShrubberyCreationForm,
				&Intern::makeRobotomyRequestForm,
				&Intern::makePresidentialPardonForm };

	for (int i = 0; i < 3; i++)
	{
		if (form.compare(check[i]) == 0)
			return ((this->*f[i])(target));
	}
	throw InvalidFormException();
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
