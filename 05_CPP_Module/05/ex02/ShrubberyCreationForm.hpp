/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:36:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 08:54:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class	Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string name );
		ShrubberyCreationForm( const ShrubberyCreationForm &sf );
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm &sf );

		void	execute( const Bureaucrat &executor ) const;

		class	FileNotOpendException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	NotSignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<( std::ostream &out, const ShrubberyCreationForm &sf );

#endif