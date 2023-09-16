/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:56:45 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/16 11:31:25 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"

class	Bureaucrat;

class	RobotoMyRequestForm : public AForm
{
	public:
		RobotoMyRequestForm();
		RobotoMyRequestForm( std::string target );
		RobotoMyRequestForm( const RobotoMyRequestForm &rf );
		~RobotoMyRequestForm();

		RobotoMyRequestForm&	operator=( const RobotoMyRequestForm &rf );

		void	execute( const Bureaucrat &executor ) const;

		class	NotSignedException : public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

#endif