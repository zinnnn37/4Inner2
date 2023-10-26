/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:18 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/26 19:16:22 by minjinki         ###   ########.fr       */
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
		std::map<std::string, float>	_data;

		BitcoinExchange();
		BitcoinExchange( const BitcoinExchange &be );

		BitcoinExchange	&operator=( const BitcoinExchange &be );

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
		~BitcoinExchange();

		void	exec();
};

#endif