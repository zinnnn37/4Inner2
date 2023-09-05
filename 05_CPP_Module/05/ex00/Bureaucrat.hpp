/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:41:37 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/05 14:00:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &b );
		~Bureaucrat();

		Bureaucrat&			operator=( const Bureaucrat &b );

		const std::string	getName() const;
		int					getGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				
		};

		class GradeTooLowException : public std::exception
		{
			public:
				
		};
};

#endif