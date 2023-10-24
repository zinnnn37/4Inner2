/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:35:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 17:33:07 by minjinki         ###   ########.fr       */
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

void	RPN::_split()
{
	std::string			buf;
	std::istringstream	iss(this->_input);
	stack<std::string>	tmp;

	while (std::getline(iss, buf, ' '))
	{
		if (buf.length() == 0)
			continue ;
		tmp.push(buf);
	}

	while (tmp.size() != 0)
	{
		this->_checkValid(tmp.top());
		this->_tmp.push(tmp.top());
		this->_len++;
		tmp.pop()	// pop 반환 값 없음
	}
}

void	RPN::_checkValid()
{

}

void	RPN::_calc()
{

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
