/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:07:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 14:59:36 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		index;
	
	public:
		PhoneBook();
		~PhoneBook();

		void	add();
		void	search();
		void	print(Contact contact);

		/* getter */
		Contact	get_contect(int index);
};

#endif