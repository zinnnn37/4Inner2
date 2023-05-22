/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:11:13 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/22 16:31:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;

	std::cout << "Enter command(ADD, SEARCH, EXIT): ";
	while (std::getline(std::cin, cmd))
	{
		if (std::cin.eof())
			continue ;
		if (cmd == "EXIT")
			phonebook.exit();
		else if (cmd == "ADD")
			phonebook.add();
		else if (cmd == "SEARCH")
			phonebook.search();
	std::cout << "Enter command(ADD, SEARCH, EXIT): ";
	}
}
