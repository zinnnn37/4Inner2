/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 11:02:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/20 11:54:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define RESET "\033[0m"

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm();
		AForm( std::string name, int gradeToSign, int gradeToExec );
		AForm( const AForm &form );
		virtual	~AForm();

		AForm&	operator=( const AForm &form );

		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
		void				setSigned( bool sign );
		void				beSigned( const Bureaucrat &b );
		virtual void		execute( const Bureaucrat &executor ) const;

		class	GradeTooHighException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				const char*	what() const throw();
		};

		class	AlreadySignedException : public std::exception
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

std::ostream&	operator<<( std::ostream &out, const AForm &form );

#endif