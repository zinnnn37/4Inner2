/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/19 14:33:59 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::get_firstname()
{
	return (this->firstname);
}

std::string Contact::get_lastname()
{
	return (this->lastname);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone()
{
	return (this->phone);
}