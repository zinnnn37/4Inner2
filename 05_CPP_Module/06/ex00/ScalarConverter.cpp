/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/10 11:06:45 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::_input = NULL;
char		ScalarConverter::_char = '\0';
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0.0f;
double		ScalarConverter::_double = 0.0;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const std::string s )
{
	_input = s;
	_setType( s );
}

ScalarConverter::ScalarConverter( const ScalarConverter &sc )
{
	(void)sc;
	// 동작 확인해봐야.. 아마 이렇게만 해도 될 듯
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter &sc )
{
	(void)sc;
	return (*this);
}

void	ScalarConverter::_setType( std::string s )
{
	if (!s.compare("nan") || !s.compare("nanf") || !s.compare("+inf")
		|| !s.compare("+inff") || !s.compare("-inf") || !s.compare("-inff"))
		_type = NANINF;
	else if (s.length() == 1 && !isdigit(s[0]) && !isprint(s[0]))
		_type = CHAR;
	else if (s.find_first_of("+-") != s.find_last_of("+-")	// 다른 경우 부호가 두 개 이상
		|| s.find_first_not_of("-+0123456789.ef") != std::string::npos)	// 숫자가 아닌 문자가 있는 경우
		_type = ERROR;
	else if ((s.find_first_of("+-") == 0 && s.find_first_not_of("-+0123456789") == std::string::npos)	// 부호 있는 정수
		|| s.find_first_not_of("0123456789") == std::string::npos)
	{
		long	l = std::atol(s.c_str());
		
		if (l > INT_MAX || l < INT_MIN)
			_type = ERROR;
		else
			_type = INT;
	}
	else if (s.find_first_of(".") != s.find_last_of("."))
		_type = ERROR;
	else if (s.find_first_of(".") == s.find_last_of("."))
	{
		if (!isdigit(s[s.find_first_of(".") + 1]))
			_type = ERROR;
		if (s.find_first_of("f") == s.find_last_of("f") && s[s.find_first_of("f") + 1] == '\0')
			_type = FLOAT;	// f가 있는 경우
		else
			_type = DOUBLE;
	}
	else
		_type = ERROR;
}

void	ScalarConverter::convert( std::string s )
{
	if (s.empty())
		throw InvalidInputException();
}
