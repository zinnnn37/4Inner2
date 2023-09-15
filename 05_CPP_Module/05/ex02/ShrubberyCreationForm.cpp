/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:48:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 08:55:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

std::string	ascii()
{
	std::string	tree =
	"               ,@@@@@@@,\
		,,,.   ,@@@@@@/@@,  .oo8888o.\
		,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\
	,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\
	%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\
	%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\
	`&%\\ ` /%&'    |.|        \\ '|8'\
		|o|        | |         | |\
		|.|        | |         | |\
		\\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\
	------------------------------------------------\
	";

	return (tree);
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string name )
	: AForm(name, 145, 137)
{
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
		this->setSigned(sf.getSigned());

	return (*this);
}

void	ShrubberyCreationForm::execute( const Bureaucrat& executor ) const
{
	std::string		fileName;
	std::ofstream	ofs;

	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	
	fileName = this->getName() + "_shrubbery";

	ofs.open(fileName);
	if (ofs.fail())
		throw FileNotOpendException();

	ofs << ascii();
	ofs.close();
}

const char*	ShrubberyCreationForm::FileNotOpendException::what() const throw()
{
	return ("Error: File isn't opend");
}

const char* ShrubberyCreationForm::NotSignedException::what() const throw()
{
	return ("Error: Form isn't signed");
}

std::ostream&	operator<<( std::ostream &out, const ShrubberyCreationForm &sf )
{
	std::cout << "\n============ ShrubberyCreationForm Info ============\n" << std::endl;
	out << sf.getName() << " form is "
		<< (sf.getSigned() ? "signed" : "not signed") << std::endl;
	out << sf.getName() << " form requires " << sf.getGradeToSign()
		<< " grade to sign in and " << sf.getGradeToExec()
		<< " grade to execute" << std::endl;
	std::cout << "\n====================================================" << std::endl;

	return out;
}
