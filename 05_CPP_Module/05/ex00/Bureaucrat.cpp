/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:41:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/07 11:59:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat( std::string name, int grade )
	: _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	else if (_grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat( const Bureaucrat &b )
{
	*this = b;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat&	Bureaucrat::operator=( const Bureaucrat &b )
{
	if (this != &b)
		this->_grade = b.getGrade();

	return (*this);
}

const std::string	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increase_grade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void	Bureaucrat::decrease_grade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	std::cout << "Grade is too high" << std::endl;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw
{
	std::cout << "Grade is too low" << std::endl;
}

std::ostream&	operator<<( std::ostream &out, const Bureaucrat& b )
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (out);
}

