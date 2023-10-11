/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 14:06:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::input = "";
char		ScalarConverter::_char = '\0';
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0.0f;
double		ScalarConverter::_double = 0.0;
int			ScalarConverter::_type = ERROR;

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

void	ScalarConverter::_setType( std::string s )
{
	int	cnt = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '+' || s[i] == '-')
			cnt++;
	}

	if (!s.compare("nan") || !s.compare("nanf") || !s.compare("+inf")
		|| !s.compare("+inff") || !s.compare("-inf") || !s.compare("-inff"))
		_type = NANINF;
	else if (s.length() == 1 && !isdigit(s[0]) && isprint(s[0]))
		_type = CHAR;
	else if ((s.find("e+") == std::string::npos && s.find("e-") == std::string::npos && cnt >= 2)	// 부호가 두 개 이상
		|| ((s.find("e+") != std::string::npos || s.find("e-") != std::string::npos) && cnt >= 3)	// 실수일 때 부호 두 개 이상
		|| s.find_first_not_of("+-0123456789.ef") != std::string::npos	// 숫자가 아닌 문자가 있는 경우
		|| s.find_first_of(".") != s.find_last_of(".")
		|| s.find_first_of("e") != s.find_last_of("e"))
		_type = ERROR;
	else if ((s.find_first_of("+-") == 0 && s.find_first_not_of("+-0123456789") == std::string::npos)	// 부호 있는 정수
		|| s.find_first_not_of("0123456789") == std::string::npos)
		_type = INT;
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

void	ScalarConverter::_typeChar()
{
	_char = static_cast<unsigned char>(input[0]);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::_typeInt()
{
	long	l;

	l = std::atol(input.c_str());

	_int = std::atoi(input.c_str());
	_char = static_cast<unsigned char>(l);
	_float = static_cast<float>(l);
	_double = static_cast<double>(l);

	if (l < INT_MIN || INT_MAX < l)
		_type = INTOVER;
	else if (_int < -128 || 127 < _int)
		_type = CHAROVER;
}

void	ScalarConverter::_typeFloat()
{
	double	d;

	d = std::atof(input.c_str());

	_float = std::atof(input.c_str());
	_char = static_cast<unsigned char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(d);

	if (isinf(_float))
		_type = INTOVER;
	else if (_float < -128 || 127 < _float)
		_type = CHAROVER;
}

void	ScalarConverter::_typeDouble()
{
	_double = std::strtod(input.c_str(), NULL);
	_char = static_cast<unsigned char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);

	if (isinf(_float))
		_type = INTOVER;
	else if (_double < -128 || 127 < _double)
		_type = CHAROVER;
}

void	ScalarConverter::convert()
{
	if (input.length() == 0)
		throw InvalidInputException();
	switch (_type)
	{
		case CHAR:
			_typeChar();
			break;

		case INT:
			_typeInt();
			break;

		case FLOAT:
			_typeFloat();
			break;

		case DOUBLE:
			_typeDouble();
			break;
		
		case NANINF:
			break;

		default:
			throw InvalidInputException();
	}
	_print();
}

void	ScalarConverter::_print()
{
	// char
	if (_type != NANINF && _type != CHAROVER && _type != INTOVER && _char >= 0)
	{
		if (isprint(_char))
			std::cout << "char: '" << _char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// int
	if (_type == INTOVER)
		std::cout << "int: impossible" << std::endl;
	else if (_type != NANINF && _int >= INT_MIN && _int <= INT_MAX)
		std::cout << "int: " << _int << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	// float
	if (_type != NANINF)
	{
		if (_float - static_cast<int>(_float) == 0)
			std::cout << "float: " << _float << ".0f" << std::endl;
		else
			std::cout << "float: " << _float << "f" << std::endl;
	}
	else if (!input.compare("nan") || !input.compare("nanf"))
		std::cout << "float: nanf" << std::endl;
	else
	{
		if (input[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	// double
	if (_type != NANINF)
	{
		if (_double - static_cast<int>(_double) == 0)
			std::cout << "double: " << _double << ".0" << std::endl;
		else
			std::cout << "double: " << _double << std::endl;
	}
	else if (!input.compare("nan") || !input.compare("nanf"))
		std::cout << "double: nan" << std::endl;
	else
	{
		if (input[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

void	ScalarConverter::setInput( std::string s )
{
	input = s;
	_setType(s);
}

const char	*ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid Input");
}
