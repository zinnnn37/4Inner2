/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:27:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:18:04 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	: _type("WrongAnimal")
{
}

WrongAnimal::WrongAnimal( const WrongAnimal& animal )
{
	*this = animal;
}

WrongAnimal::~WrongAnimal()
{
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
