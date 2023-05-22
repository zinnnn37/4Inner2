/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 15:57:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>
#include <cctype>

std::string replace_last(std::string s);
bool is_digit(std::string s);

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_cnt;
	
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();
		void	print();
		void	exit();


};

#endif