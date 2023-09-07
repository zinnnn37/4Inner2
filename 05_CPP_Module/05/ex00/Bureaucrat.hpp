/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:41:37 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/07 11:58:49 by minjinki         ###   ########.fr       */
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
		void				increase_grade();
		void				decrease_grade();

		class GradeTooHighException : public std::exception
		{	// exception 클래스 상속
			public:
				const char* what() const throw();
				// 예외 종류에 맞는 에러 메시지를 리턴하는 함수
				// std::exception 클래스의 what 함수를 오버라이딩
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream&	operator<<( std::ostream &out, const Bureaucrat &b );

#endif