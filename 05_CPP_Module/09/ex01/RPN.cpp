/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:35:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/26 16:38:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()	{}

RPN::RPN( std::string input )
	: _len(0), _input(input)
{
	this->exec();
}

RPN::RPN( const RPN &rpn )
{
	*this = rpn;
}

RPN::~RPN() {}

RPN	&RPN::operator=( const RPN &rpn )
{
	(void)rpn;
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
		throw "Numbers should be between 0 ~ 9";
}

void	RPN::_split()
{
	std::string				buf;
	std::istringstream		ss(this->_input);
	std::stack<std::string>	tmp;

	while (getline(ss, buf, ' '))
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
		tmp.pop();	// pop 반환 값 없음
	}
}

void	RPN::_calc()
{
	this->_split();

	if (this->_tmp.empty())
		return ;

	int			x, y;
	std::string	buf;

	while (!this->_tmp.empty())
	{
		buf = this->_tmp.top();

		if (isdigit(buf[0]))
		{
			x = atoi(buf.c_str());
			this->_rpn.push(x);
			this->_tmp.pop();
		}
		if (this->_isOp(buf[0]))
		{
			if (this->_rpn.size() < 2)
				throw "The number of nums and ops doesn't match";

			this->_tmp.pop();
			y = this->_rpn.top();
			this->_rpn.pop();
			x = this->_rpn.top();
			this->_rpn.pop();

			this->_rpn.push(this->_doOp(x, y, buf[0]));
		}
	}

	if (this->_rpn.size() > 1)
		throw "The number of nums and ops doesn't match";
	std::cout << this->_rpn.top() << std::endl;
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
	try
	{
		this->_calc();
	}
	catch(const char *e)
	{
		std::cerr << e << std::endl;
	}
	
}
