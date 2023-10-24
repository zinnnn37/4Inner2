/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 10:27:40 by minjinki         ###   ########.fr       */
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

	if (y > 2023 || y < 2009 || m > 12 || m < 1 || d < 1)
	// 비트코인 거래 시작 연도 ~ 현재
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
	//else if (r < 0)
	//	return (false);
	
	return (true);
}

void	BitcoinExchange::_readCSVFile()
{
	std::ifstream	ifs("data1.csv");
	std::string		line;

	if (ifs.fail())
		throw "Fail to open data.csv";

	if (std::getline(ifs, line).eof())
		throw "data.csv is empty";

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

//BitcoinExchange::Error::Error() {}

//BitcoinExchange::Error::Error( const char *msg ) : _msg(msg) {}

//BitcoinExchange::Error::Error( const Error &e )
//{
//	*this = e;
//}

//BitcoinExchange::Error::~Error() throw() {}

//BitcoinExchange::Error	&BitcoinExchange::Error::operator=( const Error &e )
//{
//	(void)e;
//	return (*this);
//}

//const char	*BitcoinExchange::Error::what() const throw()
//{
//	return ("Error");
//}

//const char	*BitcoinExchange::Error::getMsg() const
//{
//	return (this->_msg);
//}
