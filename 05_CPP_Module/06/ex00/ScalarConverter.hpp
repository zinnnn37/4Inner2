/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:20:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/13 19:12:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cmath>
#include <exception>
#include <iomanip>

#define ERROR -1
#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3
#define NANINF 4
#define CHAROVER -5
#define INTOVER -6
#define FLTPRECISION 7
#define DBLPRECISION 15

class	ScalarConverter
{
	private:
		static std::string	_input;
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;
		static int			_type;

		ScalarConverter();
		ScalarConverter( const ScalarConverter &sc );
		~ScalarConverter();

		static void	_setInput( const std::string s );
		static void	_setType( const std::string s );
		static void	_typeChar();
		static void	_typeInt();
		static void	_typeFloat();
		static void	_typeDouble();
		static void	_print();
		static int	_cntDigit( int n, float num );

	public:

		ScalarConverter&	operator=( const ScalarConverter &sc );
	
		static void	convert( const std::string s );

		class	InvalidInputException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

/* Static Class */
// 인스턴스화 할 수 없는 클래스
// 클래스의 모든 멤버가 static 멤버이다.
// 정적 클래스는 전역 변수와 유사한 역할을 수행하며
// 정적 변수와 마찬가지로 프로그램이 실행될 때 클래스 멤버가 초기화된다.

#endif
