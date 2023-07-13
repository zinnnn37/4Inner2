/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:27:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:31:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
	std::cout << "💥 WrongAnimal default constructor 💥" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& animal )
{
	std::cout << "💥 WrongAnimal copy constructor 💥" << std::endl;

	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "💥 WrongAnimal destructor 💥" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& animal )
{
	if (this != &animal)
		this->_type = animal._type;

	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sounds 🎶" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}
