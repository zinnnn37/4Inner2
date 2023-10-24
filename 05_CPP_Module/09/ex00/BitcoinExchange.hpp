/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:18 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 11:02:50 by minjinki         ###   ########.fr       */
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
#include <iomanip>
#include <climits>

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
		bool	_checkVal( std::string val );
		void	_compareCSVInput( std::string date, std::string val );
		void	_findDate( std::string date, std::string rate );

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