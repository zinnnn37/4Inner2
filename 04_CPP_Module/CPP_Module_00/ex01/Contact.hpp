/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 15:23:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phone;
		std::string	_secret;
	
	public:
		Contact();
		~Contact();
		Contact(std::string firstname, std::string lastname, \
			std::string nickname, std::string phone, std::string secret);

		/* getter */
		std::string	get_firstname() const;
		std::string	get_lastname() const;
		std::string	get_nickname() const;
		std::string	get_phone() const;
		std::string get_secret() const;
		
		/* setter */
		void set_firstname(std::string s);
		void set_lastname(std::string s);
		void set_nickname(std::string s);
		void set_phone(std::string s);
		void set_secret(std::string s);
};

#endif