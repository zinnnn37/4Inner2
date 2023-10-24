/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:35:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 17:49:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()	{}

RPN::RPN( std::string input )
	: _len(0), _input(input)
{
	
}

RPN::RPN( const RPN &rpn )
{
	*this = rpn;
}

RPN::~RPN() {}

RPN	&RPN::operator=( const RPN &rpn )
{
	if (this != &rpn)
	{
		this->_input = rpn->_input;
	}
	return (*this);
}

bool	RPN::_isOp( char c )
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::_checkValid( std::string s )
{
	if (s.length() == 1 && this->_isOp(s[0]))
		return ;
	
	char	*end;
	long	l = strtol(s.c_str(), &end, 10);

	if (*end)
		throw "Invalid value";
	if (l < 0 || l >= 10)
		throw "Input numbers between 0 ~ 9";
}

void	RPN::_split()
{
	std::string			buf;
	std::stringstream	ss(this->_input);
	stack<std::string>	tmp;

	while (getline(iss, buf, ' '))
	{
		if (buf.length() == 0)
			continue ;
		tmp.push(buf);
	}

	while (!tmp.empty())
	{
		this->_checkValid(tmp.top());
		this->_tmp.push(tmp.top());
		this->_len++;
		tmp.pop()	// pop 반환 값 없음
	}
}

void	RPN::_calc()
{
	std::string	buf;

	while (!this->_tmp.empty())
	{
		buf = this->_tmp.top()
	}
}

int	RPN::_doOp( int x, int y, char op )
{
	if (op == '+')
		return (x + y);
	else if (op == '-')
		return (x - y);
	else if (op == '*')
		return (x * y);
	else if (op == '/' and y != 0)
		return (x / y);
	
	throw "Zero devision Error";
}

void	RPN::exec()
{
	
}
