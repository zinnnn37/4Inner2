/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 16:14:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string replace_last(std::string s)
{
	if (s.length() > 10)
		s[9] = '.';
	s[10] = '\0';
	return (s);
}

bool is_digit(std::string s)
{
	for (int i = 0; i < s.length(); i++)
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

// display에서 setw(10) 함수 사용하기
void PhoneBook::print()
{
	std::string	s;
	for (int i = 0; i < this->_cnt; i++)
	{
		/* index */
		std::cout << std::setw(10) << i;
		std::cout << "|";
		/* first name */
		s = replace_last(this->_contacts[i].get_firstname());
		std::cout << setw(10) << s;
		std::cout << "|";
		/* last name */
		s = replace_last(this->_contacts[i].get_lastname());
		std::cout << setw(10) << s;
		std::cout << "|";
		/* nickname */
		s = replace_last(this->_contacts[i].get_nickname());
		std::cout << setw(10) << s << std::endl;
	}
}

void PhoneBook::search()
{
	int			icmd;
	std::string	cmd;

	print();

	while (true)
	{
		std::cout << "Enter index(press '9' to stop searching): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			continue ;
		if (!is_digit(cmd))
			std::cout << "Contains non-numeric characters!" << endl;
		else if (cmd.length() > 1 || cmd[0] == '8')
			std::cout << "Index out of range!" << endl;
		else if (cmd)
		{
			icmd = cmd[0] - '0';
			if (icmd == 9)
				break ;
			else if (icmd > this->_cnt)
			{
				std::cout << "Index out of range!" << endl;
				continue ;
			}
			
		}
		continue ;
	}
}

void PhoneBook::exit()
{
	std::exit(0);
}
