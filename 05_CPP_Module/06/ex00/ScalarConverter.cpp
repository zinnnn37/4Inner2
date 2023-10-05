/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/05 12:38:31 by minjinki         ###   ########.fr       */
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
}
