/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 08:46:51 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/07 14:04:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		Intern();
		Intern( const Intern &intern );
		~Intern();

		Intern&	operator=( const Intern &intern );

		AForm*	makeForm( std::string form, std::string target );
		AForm*	makeShrubberyCreationForm( std::string target );
		AForm*	makeRobotomyRequestForm( std::string target );
		AForm*	makePresidentialPardonForm( std::string target );

		class	InvalidFormException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif