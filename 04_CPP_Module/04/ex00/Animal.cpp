/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:27 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:22:41 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: _type("Animal")
{
	std::cout << "🎶 Animal default constructor 🎶" << std::endl;
}

Animal::Animal( const Animal& animal )
{
	std::cout << "🎶 Animal copy constructor 🎶" << std::endl;

	*this = animal;
}

Animal::~Animal()
{
	std::cout << "🎶 Animal destructor 🎶" << std::endl;
}

Animal&	Animal::operator=( const Animal& animal )
{
	if (this != &animal)
		this->_type = animal._type;

	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Undefined sounds 🎶" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}
