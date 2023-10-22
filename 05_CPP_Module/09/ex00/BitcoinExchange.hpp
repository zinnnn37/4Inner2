/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:37:18 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/22 17:17:05 by minjinki         ###   ########.fr       */
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
		float							_val;
		std::string						_date;
		std::map<std::string, float>	_data;

		BitcoinExchange();

	public:
		BitcoinExchange( const BitcoinExchange &be );
		~BitcoinExchange();

		BitcoinExchange	&operator=( const BitcoinExchange &be );

};

#endif