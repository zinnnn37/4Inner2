/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:48:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/24 14:59:10 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

std::string	ascii()
{
	std::string	tree =
	"             ,@@@@@,\n\
	,...,  ,@@@@@@/@@,  .o8888o.\n\
  ,&%%&%&&%,@@@@@/@@@888,8888\\88`\n\
,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88\"\n\
%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
`&%\\ ` /%&'    |.|        \\ '|8'\n\
	|o|        | |         | |\n\
	|.|        | |         | |\n\
	\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n\
---------------------------------------------";

	return (tree);
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &sf )
	: AForm(sf.getName(), sf.getGradeToSign(), sf.getGradeToExec())
{
	*this = sf;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=( const ShrubberyCreationForm &sf )
{
	if (this != &sf)
	{
		this->setSigned(sf.getSigned());
		this->_target = sf._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	const char		*file;
	std::string		fileName;
	std::ofstream	ofs;

	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	
	fileName = this->getTarget();
	fileName.append("_shrubbery");
	file = fileName.c_str();

	ofs.open(file);
	if (ofs.fail())
		throw FileNotOpendException();

	ofs << ascii();
	ofs.close();

	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	std::cout << GREEN"Shrubbery is planted in " << this->getTarget() << RESET << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

const char*	ShrubberyCreationForm::FileNotOpendException::what() const throw()
{
	red();
	return ("Error: File isn't opend");
}

const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
	red();
	return ("Error: Form isn't signed");
}

std::ostream&	operator<<( std::ostream &out, const ShrubberyCreationForm &sf )
{
	out << "\n============ ShrubberyCreationForm Info ============\n" << std::endl;
	out << sf.getName() << " form is "
		<< (sf.getSigned() ? "signed" : "not signed") << std::endl;
	out << sf.getName() << " form requires " << sf.getGradeToSign()
		<< " grade to sign and " << sf.getGradeToExec()
		<< " grade to execute" << std::endl;
	out << "\n====================================================" << std::endl;

	return out;
}
