/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/22 18:04:49 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( std::string input )
	: _input(input)
{
	this->readCSVFile();
	this->readInputFile();
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

bool	BitcoinExchange::checkDate( std::string date )
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
		return (false);
	else if (d > 31)
		return (false);
	else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
		return (false);
	else if (m == 2 && d > 28)
		return (false);
}

void	BitcoinExchange::readCSVFile()
{
	std::ifstream	ifs("data.csv");
	std::string		line;

	if (ifs.fail())
		throw BitcoinExchange::Error("Fail to open data.csv");

	if (std::getline(ifs, line).eof())
		throw BitcoinExchange::Error("data.csv is empty");

	getline(ifs, line);

	while (!ifs.eof())
	{
		getline(ifs, line);

		std::stringstream	ss(line);
		std::string			date, rate;

		getline(ss, date, ',');
		getline(ss, rate);
		
		if (!checkDate(date) || !checkRate(rate))
			throw BitcoinExchange::Error("data.csv has invalid value");
		this->_data[date] = atof(rate.c_str());
	}

	ifs.close();
}

BitcoinExchange::Error::Error() {}

BitcoinExchange::Error::Error( std::string msg ) : _msg(msg) {}

BitcoinExchange::Error::Error( const Error &e )
{
	*this = e;
}

BitcoinExchange::Error::~Error() throw() {}

BitcoinExchange::Error	&BitcoinExchange::Error::operator=( const Error &e )
{
	(void)e;
	return (*this);
}

const char	*BitcoinExchange::Error::what() const throw()
{
	return ("Error");
}

const char	*BitcoinExchange::Error::getMsg() const
{
	return (this->_msg);
}
