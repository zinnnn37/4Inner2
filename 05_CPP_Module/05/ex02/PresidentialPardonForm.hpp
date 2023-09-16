/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:28:20 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 18:48:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &pf );
		virtual ~PresidentialPardonForm();

		PresidentialPardonForm&	operator=( const PresidentialPardonForm &pf );

		virtual void	execute( const Bureaucrat &executor ) const;
		std::string		getTarget() const;

		class	NotSignedException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
}

std::ostream&	operator<<( std::ostream &out, const PresidentialPardonForm &pf );

#endif