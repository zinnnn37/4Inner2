/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:41:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 08:56:25 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("default_form"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExec )
	: _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm &form )
	: _name(form.getName()), _gradeToSign(form.getGradeToSign()), _gradeToExec(form.getGradeToExec())
{
	*this = form;
}

AForm::~AForm()
{
}

AForm&	AForm::operator=( const AForm &form )
{
	if (this != &form)
		this->_signed = form.getSigned();

	return (*this);
}

const std::string	AForm::getName() const
{
	return (this->_name);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	AForm::setSigned( bool sign )
{
	this->_signed = sign;
}

void	AForm::beSigned( const Bureaucrat &b )
{
	if (b.getGrade() > this->_gradeToSign || b.getGrade() > this->_gradeToExec)
	{
		std::cout << b.getName() << " couldn't sign " << this->_name
			<< " because their grade is too low" << std::endl;
		throw GradeTooLowException();
	}
	else if (this->_signed == true)
	{
		std::cout << b.getName() << " couldn't sign " << this->_name
			<< " because it's already signed" << std::endl;
		throw AlreadySignedException();
	}
	else
		this->setSigned(true);
}

void	AForm::execute( const Bureaucrat &executor ) const
{
	std::cout << executor.getName() << " executed in AForm\n" << std::endl;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low");
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return ("Error: Already signed");
}

std::ostream&	operator<<( std::ostream &out, const AForm &form )
{
	std::cout << "\n==================== Form Info ====================\n" << std::endl;
	out << form.getName() << " form is "
		<< (form.getSigned() ? "signed" : "not signed") << std::endl;
	out << form.getName() << " form requires " << form.getGradeToSign()
		<< " grade to sign in and " << form.getGradeToExec()
		<< " grade to execute" << std::endl;
	std::cout << "\n===================================================" << std::endl;

	return out;
}
