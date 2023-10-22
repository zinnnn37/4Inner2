/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:04 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/22 17:28:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( std::string input )
	: _input(input)
{
	this->readFile();
	this->parsing();
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



BitcoinExchange::Error::Error() {}

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
