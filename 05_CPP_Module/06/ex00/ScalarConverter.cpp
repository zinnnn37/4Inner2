/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 17:21:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/15 14:06:05 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

std::string	ScalarConverter::_input = "";
char		ScalarConverter::_char = '\0';
int			ScalarConverter::_int = 0;
float		ScalarConverter::_float = 0.0f;
double		ScalarConverter::_double = 0.0;
int			ScalarConverter::_type = DEFAULT;
int			ScalarConverter::_over = DEFAULT;

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

void	ScalarConverter::convert( std::string input )
{
	_setInput(input);

	if (_input.length() == 0)
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

void	ScalarConverter::_setInput( std::string s )
{
	_input = s;
	_setType(s);
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
		|| s.find_first_of("e") != s.find_last_of("e")
		|| s.find_first_of("f") != s.find_last_of("f"))
		_type = ERROR;
	else if ((s.find_first_of("+-") == 0 && s.find_first_not_of("+-0123456789") == std::string::npos)	// 부호 있는 정수
		|| s.find_first_not_of("0123456789") == std::string::npos)
		_type = INT;
	else if (s.find_first_of(".") == s.find_last_of("."))
	{
		if (!isdigit(s[s.find_first_of(".") + 1]))
			_type = ERROR;
		if (s.find_first_of("f") && s[s.find_first_of("f") + 1] == '\0')
			_type = FLOAT;	// f가 있는 경우
		else
			_type = DOUBLE;
	}
	else
		_type = ERROR;
}

void	ScalarConverter::_typeChar()
{
	_char = static_cast<unsigned char>(_input[0]);
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::_typeInt()
{
	long	l;

	l = std::atol(_input.c_str());

	_int = std::atoi(_input.c_str());
	_char = static_cast<unsigned char>(_int);
	_float = static_cast<float>(l);
	_double = static_cast<double>(l);

	_checkOverflow(l);
}

void	ScalarConverter::_typeFloat()
{
	long	l;
	double	d;

	d = std::atof(_input.c_str());

	_float = std::atof(_input.c_str());
	_char = static_cast<unsigned char>(_float);
	_double = static_cast<double>(d);

	l = static_cast<long>(d);
	_int = static_cast<int>(l);

	_checkOverflow(l);
}

void	ScalarConverter::_typeDouble()
{
	long	l;

	_double = std::strtod(_input.c_str(), NULL);
	_char = static_cast<unsigned char>(_double);
	_float = static_cast<float>(_double);

	l = static_cast<long>(_double);
	_int = static_cast<int>(l);

	_checkOverflow(l);
}

void	ScalarConverter::_checkOverflow( long l )
{
	if (l > INT_MAX || l < INT_MIN)
		_over = INTOVER;
	else if (l < -128 || l > 127)
		_over = CHAROVER;
}

void	ScalarConverter::_print()
{
	//std::cout << _type << std::endl;

	// char
	if (_type != NANINF && _over != CHAROVER && _over != INTOVER && _char >= 0)
	{
		if (isprint(_char))
			std::cout << "char: '" << _char << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;

	// int
	if (_type != NANINF && _over != INTOVER)
		std::cout << "int: " << _int << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	
	// float
	if (_type != NANINF)
	{
		if (std::isinf(_float) && _float > 0)
			std::cout << "float: +inff" << std::endl;
		else if (_float - static_cast<int>(_float) == 0 && _cntDigit(FLTPRECISION, _float) == 0)
			std::cout << "float: " << std::setprecision(FLTPRECISION) << _float << ".0f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(FLTPRECISION) << _float << "f" << std::endl;
	}
	else if (!_input.compare("nan") || !_input.compare("nanf"))
		std::cout << "float: nanf" << std::endl;
	else
	{
		if (_input[0] == '+')
			std::cout << "float: +inff" << std::endl;
		else
			std::cout << "float: -inff" << std::endl;
	}

	// double
	if (_type != NANINF)
	{
		if (std::isinf(_double) && _double > 0)
			std::cout << "double: +inf" << std::endl;
		else if (_type != DOUBLE && _type != FLOAT)
		{
			if (_cntDigit(DBLPRECISION, _double) == 0)
				std::cout << "double: " << std::setprecision(DBLPRECISION) << _double << ".0" << std::endl;
			else
				std::cout << "double: " << std::setprecision(DBLPRECISION) << _double << std::endl;
		}
		else if (_double - static_cast<long>(_double) == 0)	// 값 자체는 정수이나 실수형으로 들어오는 경우
			std::cout << "double: " << std::setprecision(DBLPRECISION) << _double << ".0" << std::endl;
		else
			std::cout << "double: " << std::setprecision(DBLPRECISION) << _double << std::endl;
	}
	else if (!_input.compare("nan") || !_input.compare("nanf"))
		std::cout << "double: nan" << std::endl;
	else
	{
		if (_input[0] == '+')
			std::cout << "double: +inf" << std::endl;
		else
			std::cout << "double: -inf" << std::endl;
	}
}

int	ScalarConverter::_cntDigit( int n, float num )
{
	while (n--)
	{
		num /= 10;
	}
	return (static_cast<int>(num));
}

const char	*ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid Input");
}
