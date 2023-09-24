/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:28:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/24 14:59:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &pf )
	: AForm(pf.getName(), pf.getGradeToSign(), pf.getGradeToExec())
{
	*this = pf;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=( const PresidentialPardonForm &pf )
{
	if (this != &pf)
	{
		this->setSigned(pf.getSigned());
		this->_target = pf.getTarget();
	}
	return (*this);
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();

	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	green();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	reset();
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

const char*	PresidentialPardonForm::NotSignedException::what() const throw()
{
	red();
	return ("Error: Form isn't signed.");
}

std::ostream&	operator<<( std::ostream &out, const PresidentialPardonForm &pf )
{
	std::cout << "\n\n============ PresidentialPardonForm Info ============\n" << std::endl;
	out << pf.getName() << " form is "
		<< (pf.getSigned() ? "signed" : "not signed") << std::endl;
	out << pf.getName() << " form requires " << pf.getGradeToSign()
		<< " grade to sign and " << pf.getGradeToExec()
		<< " grade to execute" << std::endl;
	out << "\n=====================================================" << std::endl;

	return out;
}
