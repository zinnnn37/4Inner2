/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:18 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/22 17:58:24 by minjinki         ###   ########.fr       */
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
		std::map<std::string, float>	_data;

		void	readCSVFile();
		void	readInputFile();
		bool	checkDate( std::string date );
		bool	checkRate( std::string rate );

	public:
		BitcoinExchange();
		BitcoinExchange( std::string input );
		BitcoinExchange( const BitcoinExchange &be );
		~BitcoinExchange();

		BitcoinExchange	&operator=( const BitcoinExchange &be );

	class	Error : public std::exception
	{
		private:
			const char	*_msg;

		public:
			Error();
			Error( const char *msg );
			Error( const Error &e );
			~Error() throw();

			Error	&operator=( const Error &e );

			const char	*what() const throw();
			const char	*getMsg() const;
	};
};

#endif