/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/24 11:46:13 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>

std::string replace_last(std::string s);
bool is_digit(std::string s);

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_cnt;

		void	_print();
	
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();
		void	exit();
		void	run();
};

#endif