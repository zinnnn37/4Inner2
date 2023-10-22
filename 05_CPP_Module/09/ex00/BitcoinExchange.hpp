/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:18 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/22 17:27:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>

class	BitcoinExchange
{
	private:
		std::string						_input;
		std::map<std::string, float>	_data;


		void	readFile();
		void	parsing();

	public:
		BitcoinExchange();
		BitcoinExchange( std::string input );
		BitcoinExchange( const BitcoinExchange &be );
		~BitcoinExchange();

		BitcoinExchange	&operator=( const BitcoinExchange &be );

		void	execute();

	class	Error : public std::exception
	{
		public:
			Error();
			Error( const Error &e );
			~Error() throw();

			Error	&operator=( const Error &e );

			const char	*what() const throw();
	};
};

#endif