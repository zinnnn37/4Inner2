/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/23 19:48:26 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter( const ScalarConverter &sc )
{
	(void)sc;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter&	ScalarConverter::operator=( const ScalarConverter &sc )
{
	(void)sc;
	return (*this);
}

bool	ScalarConverter::isValid( std::string str )
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (false);
	if (str.length() == 2 && !isdigit(str[0]) && str[0] != '-' && !isdigit(str[1]))
		return (false);
	if (str.length() == 3 && !isdigit(str[0]) && str[0] != '-' && !isdigit(str[1]) && str[1] != '.' && !isdigit(str[2]))
		return (false);
	return (true);
}

void	ScalarConverter::_toInt( std::string str )
{
	double		res;
	const char *c_str;

	c_str = str.c_str();
	res = std::strtod(c_str, NULL);
	this->_int = res;
}

void	ScalarConverter::convert( std::string str )
{
	std::cout << isValid(str) << std::endl;
	std::cout << str << std::endl;
	// std::cout << _toInt(str.c_str()) << std::endl;
}
