/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:53 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/24 17:53:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	replace_last( std::string s )
{
	std::string	ret;

	if (s.length() > 10)
		s[9] = '.';
	for (unsigned long i = 10; i < s.size(); i++)
		s[i] = '\0';
	return (s);
}

bool	is_digit( std::string s )
{
	for (unsigned long i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool	is_space_only( std::string s )
{
	bool	flag;
	
	flag = false;
	for (unsigned long i = 0; i < s.size(); i++)
	{
		if (!std::isspace(s[i]))
			flag = true;
	}
	return (flag);
}

PhoneBook::PhoneBook()
	: _index(0), _cnt(0)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	std::string	s;

	std::cout << std::endl << "First Name: ";
	while (std::getline(std::cin, s))
	{
		if (std::cin.eof() || s.size() == 0 || !is_space_only(s))
		{
			std::cout << "First Name: ";
			continue ;
		}
		this->_contacts[this->_index].set_firstname(s);
		break ;
	}

	std::cout << "Last Name: ";
	while (std::getline(std::cin, s))
	{
		if (std::cin.eof() || s.size() == 0 || !is_space_only(s))
		{
			std::cout << "Last Name: ";
			continue ;
		}
		this->_contacts[this->_index].set_lastname(s);
		break ;
	}

	std::cout << "Nickname: ";
	while (std::getline(std::cin, s))
	{
		if (std::cin.eof() || s.size() == 0 || !is_space_only(s))
		{
			std::cout << "Nickname: ";
			continue ;
		}
		this->_contacts[this->_index].set_nickname(s);
		break ;
	}

	std::cout << "Phone Number: ";
	while (std::getline(std::cin, s))
	{
		if (std::cin.eof() || s.size() == 0 || !is_space_only(s))
		{
			std::cout << "Phone Number: ";
			continue ;
		}
		this->_contacts[this->_index].set_phone(s);
		break ;
	}

	std::cout << "Your Darkest Secret: ";
	while (std::getline(std::cin, s))
	{
		if (std::cin.eof() || s.size() == 0 || !is_space_only(s))
		{
			std::cout << "Your Darkest Secret: ";
			continue ;
		}
		this->_contacts[this->_index].set_secret(s);
		break ;
	}

	this->_index = (this->_index + 1) % 8;
	if (this->_cnt < 8)
		this->_cnt++;

	std::cout << std::endl;
}

void	PhoneBook::_print()
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
	std::cout << std::endl;
}

void	PhoneBook::search()
{
	int			icmd;
	std::string	cmd;
	Contact		contact;

	_print();

	while (true)
	{
		std::cout << "Enter index(press '9' to stop searching): ";
		std::getline(std::cin, cmd);
		if (std::cin.eof() || cmd.size() == 0)
			continue ;
		if (!is_digit(cmd))
			std::cout << "Contains non-numeric characters!" << std::endl;
		else if (cmd.size() > 1 || cmd[0] == '8')
			std::cout << "Index out of range!" << std::endl;
		else
		{
			icmd = cmd[0] - '0';
			if (icmd == 9)
				break ;
			else if (icmd > this->_cnt - 1)
			{
				std::cout << "Index out of range!" << std::endl << std::endl;
				continue ;
			}
			contact = this->_contacts[icmd];
			std::cout << "First Name: " << contact.get_firstname() << std::endl;
			std::cout << "Last Name: " << contact.get_lastname() << std::endl;
			std::cout << "Nickname: " << contact.get_nickname() << std::endl;
			std::cout << "Phone: " << contact.get_phone() << std::endl;
			std::cout << "Darkest Secret: " << contact.get_secret() << std::endl;
		}
		std::cout << std::endl;
		continue ;
	}
	std::cout << std::endl;
}

void	PhoneBook::exit()
{
	std::exit(0);
}

void	PhoneBook::run()
{
	std::string	cmd;

	std::cout << std::endl << "================= PHONE BOOK =================" << std::endl;
	std::cout << "Enter command(ADD, SEARCH, EXIT): ";
	while (std::getline(std::cin, cmd))
	{
		if (std::cin.eof())
			continue ;
		if (cmd == "EXIT")
			this->exit();
		else if (cmd == "ADD")
			this->add();
		else if (cmd == "SEARCH")
			this->search();
		std::cout << std::endl << "================= PHONE BOOK =================" << std::endl;
		std::cout << "Enter command(ADD, SEARCH, EXIT): ";
	}
}