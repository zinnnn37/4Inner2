/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 16:46:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string replace_last(std::string s)
{
	std::string	ret;

	if (s.length() > 10)
		s[9] = '.';
	for (unsigned long i = 10; i < s.length(); i++)
		s[i] = '\0';
	return (s);
}

bool is_digit(std::string s)
{
	for (unsigned long i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

PhoneBook::PhoneBook()
{
	this->_index = 0;
	this->_cnt = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add()
{
	std::string	s;

	// 이거 입력 while로 감싸서 length > 0인 거 나올때까지 받도록..
	std::cout << "First Name: ";
	std::getline(std::cin, s);
	this->_contacts[this->_index].set_firstname(s);

	std::cout << "Last Name: ";
	std::getline(std::cin, s);
	this->_contacts[this->_index].set_lastname(s);

	std::cout << "Nickname: ";
	std::getline(std::cin, s);
	this->_contacts[this->_index].set_nickname(s);

	std::cout << "Phone Number: ";
	std::getline(std::cin, s);
	this->_contacts[this->_index].set_phone(s);

	std::cout << "Your Darkest Secret: ";
	std::getline(std::cin, s);
	this->_contacts[this->_index].set_secret(s);

	this->_index = (this->_index + 1) % 8;
	if (this->_cnt < 7)
		this->_cnt++;
}

void PhoneBook::_print()
{
	std::string	s;

	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST" << "|"\
		<< std::setw(10) << "LAST" << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;


	for (int i = 0; i < this->_cnt; i++)
	{
		/* index */
		std::cout << "|" << std::setw(10) << i << "|";
		/* first name */
		s = replace_last(this->_contacts[i].get_firstname());
		std::cout << std::setw(10) << s << "|";
		/* last name */
		s = replace_last(this->_contacts[i].get_lastname());
		std::cout << std::setw(10) << s;
		std::cout << "|";
		/* nickname */
		s = replace_last(this->_contacts[i].get_nickname());
		std::cout << std::setw(10) << s << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

void PhoneBook::search()
{
	int			icmd;
	std::string	cmd;
	Contact		contact;

	_print();

	while (true)
	{
		std::cout << "Enter index(press '9' to stop searching): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			continue ;
		if (!is_digit(cmd))
			std::cout << "Contains non-numeric characters!" << std::endl;
		else if (cmd.length() > 1 || cmd[0] == '8')
			std::cout << "Index out of range!" << std::endl;
		else
		{
			icmd = cmd[0] - '0';
			if (icmd == 9)
				break ;
			else if (icmd > this->_cnt - 1)
			{
				std::cout << "Index out of range!" << std::endl;
				continue ;
			}
			contact = this->_contacts[icmd];
			std::cout << "First Name: " << contact.get_firstname() << std::endl;
			std::cout << "Last Name: " << contact.get_lastname() << std::endl;
			std::cout << "Nickname: " << contact.get_nickname() << std::endl;
			std::cout << "Phone: " << contact.get_phone() << std::endl;
			std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
		}
		continue ;
	}
}

void PhoneBook::exit()
{
	std::exit(0);
}
