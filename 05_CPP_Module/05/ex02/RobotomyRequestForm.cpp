/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:56:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 18:22:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &rf )
	: AForm(rf.getName(), rf.getGradeToSign(), rf.getGradeToExec())
{
	*this = rf;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=( const RobotomyRequestForm &rf )
{
	if (this != &rf)
	{
		this->setSigned(rf.getSigned());
		this->_target = rf.getTarget();
	}
	return (*this);
}

void	RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	int	random = rand() % 2;

	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();

	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	std::cout << "Bzzzzz..." << std::endl;

	if (random)
		std::cout << BLUE << this->_target << " has been robotomized" << RESET << std::endl;
	else
		std::cout << RED << this->_target << " robotomization failed" << RESET << std::endl;
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

const char* RobotomyRequestForm::NotSignedException::what() const throw()
{
	return ("Error: Form isn't signed");
}

std::ostream&	operator<<( std::ostream &out, const RobotomyRequestForm &rf )
{
	std::cout << "\n============= RobotomyRequestForm Info =============\n" << std::endl;
	out << rf.getName() << " form is "
		<< (rf.getSigned() ? "signed" : "not signed") << std::endl;
	out << rf.getName() << " form requires " << rf.getGradeToSign()
		<< " grade to sign and " << rf.getGradeToExec()
		<< " grade to execute" << std::endl;
	out << "\n====================================================\n" << std::endl;

	return out;
}
