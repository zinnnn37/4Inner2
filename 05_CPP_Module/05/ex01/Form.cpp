/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 08:41:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/26 13:40:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("default_form"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form( std::string name, int gradeToSign, int gradeToExec )
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw GradeTooHighException();
	else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form( const Form &form )
	: _name(form.getName()), _gradeToSign(form.getGradeToSign()), _gradeToExec(form.getGradeToExec())
{
	*this = form;
}

Form::~Form()
{
}

Form&	Form::operator=( const Form &form )
{
	if (this != &form)
		this->_signed = form.getSigned();

	return (*this);
}

const std::string	Form::getName() const
{
	return (this->_name);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (this->_gradeToExec);
}

void	Form::setSigned( bool sign )
{
	this->_signed = sign;
}

void	Form::beSigned( const Bureaucrat &b )
{
	if (b.getGrade() > this->_gradeToSign)
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

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade is too low");
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return ("Error: Already signed");
}

std::ostream&	operator<<( std::ostream &out, const Form &form )
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
