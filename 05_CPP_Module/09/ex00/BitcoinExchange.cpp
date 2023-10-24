/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 18:32:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( std::string input )
	: _input(input)
{
	this->_readCSVFile();
	this->_readInputFile();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange &be )
{
	*this = be;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange	&BitcoinExchange::operator=( const BitcoinExchange &be )
{
	if (this != &be)
	{
		this->_data.clear();
		std::map<std::string, float>::const_iterator it;

		for (it = be._data.begin(); it != be._data.end(); it++)
			this->_data[it->first] = it->second;
	}
	return (*this);
}

bool	BitcoinExchange::_checkDate( std::string date )
{
	std::stringstream	ss(date);
	std::string			year, month, day;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	getline(ss, year, '-');
	getline(ss, month, '-');
	getline(ss, day);

	int	y = atoi(year.c_str());
	int	m = atoi(month.c_str());
	int	d = atoi(day.c_str());

	if (y > 2022 || y < 2009 || m > 12 || m < 1 || d < 1
		|| (y == 2009 && m == 1 && d < 2))
		return (false);
	else if (d > 31)
		return (false);
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return (false);
	else if (m == 2 && (d > 28 || (this->_isLeap(y) && d > 29)))
		return (false);

	return (true);
}

bool	BitcoinExchange::_isLeap( int year )
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return (true);
	return (false);
}

bool	BitcoinExchange::_checkRate( std::string rate )
{
	char	*endptr;
	double	r = strtod(rate.c_str(), &endptr);

	(void)r;
	if (!isdigit(rate[0]) && rate[0] != '+')	// 맨 앞이 숫자나 +가 아니면
		return (false);
	
	std::string	str(endptr);

	if (*endptr && str.compare("f") != 0)	// endptr에 든 값이 f가 아니면
		return (false);
	
	return (true);
}

void	BitcoinExchange::_readCSVFile()
{
	std::ifstream	ifs("data.csv");
	std::string		line;

	if (ifs.fail())
		throw "Fail to open data.csv";

	getline(ifs, line);

	while (!ifs.eof())
	{
		getline(ifs, line);

		if (line.size() == 0)
			continue;

		std::stringstream	ss(line);
		std::string			date, rate;

		getline(ss, date, ',');
		getline(ss, rate);
		
		if (!_checkDate(date) || !_checkRate(rate))
			throw "data.csv has invalid value";

		this->_data[date] = atof(rate.c_str());
	}

	ifs.close();
}

void	BitcoinExchange::_findDate( std::string date, std::string val )
{
	if (this->_data.find(date) != this->_data.end())
	{
		float	res = atof(val.c_str()) * this->_data[date];
		std::cout << date << " => " << val
			<< " = " << res << std::endl;
	}
	else
	{
		std::map<std::string, float>::iterator	it;

		it = this->_data.lower_bound(date);
		if (it == this->_data.end())
			std::cout << "Error: Cannot find the date close to " << date << std::endl;
		else
		{
			float	res = atof(val.c_str()) * it->second;
			std::cout << date << " => " << val
				<< " = " << res << std::endl;
		}
	}
}

bool	BitcoinExchange::_checkVal( std::string val )
{
	float	v = atof(val.c_str());
	long	l = atol(val.c_str());

	if (v < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (l > INT_MAX)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}

	return (true);
}

void	BitcoinExchange::_compareCSVInput( std::string date, std::string val )
{
	if (!this->_checkDate(date))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	if (!this->_checkVal(val))
	{
		return ;
	}

	_findDate(date, val);
}

void	BitcoinExchange::_readInputFile()
{
	std::ifstream	ifs(this->_input.c_str());
	std::string		line;

	if (ifs.fail())
		throw "Fail to open input file";

	getline(ifs, line);
	if (line.compare("date | value") != 0)
		throw "input file has invalid format";

	while (!ifs.eof())
	{
		getline(ifs, line);

		if (line.size() == 0)
			continue;

		std::stringstream	ss(line);
		std::string			date, val, del;

		getline(ss, date, ' ');
		getline(ss, del, ' ');
		getline(ss, val);

		if (del.length() > 0 && del.compare("|") != 0)
			throw "input file has invalid format";

		_compareCSVInput(date, val);
	}

	ifs.close();
}
