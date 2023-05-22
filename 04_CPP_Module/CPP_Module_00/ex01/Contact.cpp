/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 15:23:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

Contact::Contact(std::string firstname, std::string lastname, \
			std::string nickname, std::string phone, std::string secret)
{
}

std::string Contact::get_firstname() const
{
	return (this->_firstname);
}

std::string Contact::get_lastname() const
{
	return (this->_lastname);
}

std::string Contact::get_nickname() const
{
	return (this->_nickname);
}

std::string Contact::get_phone() const
{
	return (this->_phone);
}

std::string Contact::get_secret() const
{
	return (this->_secret);
}

void Contact::set_firstname(std::string s)
{
	this->_firstname = s;
}

void Contact::set_lastname(std::string s)
{
	this->_lastname = s;
}

void Contact::set_nickname(std::string s)
{
	this->_nickname = s;
}

void Contact::set_phone(std::string s)
{
	this->_phone = s;
}

void Contact::set_secret(std::string s)
{
	this->_secret = s;
}