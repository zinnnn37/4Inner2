/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:20:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/23 19:45:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <exception>

class	ScalarConverter
{
	private:
		int		_int;
		char	_char;
		float	_float;
		double	_double;

		ScalarConverter();

		static void	_toInt( std::string str );
		static void	_toChar( char *str );
		static void	_toFloat( char *str );
		static void	_toDouble( char *str );

	public:
		ScalarConverter( const ScalarConverter &sc );
		~ScalarConverter();

		ScalarConverter&	operator=( const ScalarConverter &sc );

		static void	convert( std::string str );

		static bool	isValid( std::string str );

		class	ImpossibleException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("impossible");
				}
		};
};

/* Static Class */
// 인스턴스화 할 수 없는 클래스
// 클래스의 모든 멤버가 static 멤버이다.
// 정적 클래스는 전역 변수와 유사한 역할을 수행하며
// 정적 변수와 마찬가지로 프로그램이 실행될 때 클래스 멤버가 초기화된다.

#endif
