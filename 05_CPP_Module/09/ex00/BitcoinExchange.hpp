/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:18 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 10:15:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <sstream>

class	BitcoinExchange
{
	private:
		std::string						_input;
		char							*_test;
		std::map<std::string, float>	_data;

		BitcoinExchange();

		void	_readCSVFile();
		void	_readInputFile();
		bool	_checkDate( std::string date );
		bool	_isLeap( int year );
		bool	_checkRate( std::string rate );

	public:
		BitcoinExchange( std::string input );
		BitcoinExchange( const BitcoinExchange &be );
		~BitcoinExchange();

		BitcoinExchange	&operator=( const BitcoinExchange &be );

	//class	Error : public std::exception
	//{
	//	private:
	//		const char	*_msg;

	//	public:
	//		Error();
	//		Error( const char *msg );
	//		Error( const Error &e );
	//		~Error() throw();

	//		Error	&operator=( const Error &e );

	//		const char	*what() const throw();
	//		const char	*getMsg() const;
	//};
};

#endif