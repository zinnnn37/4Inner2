/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:27 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 16:37:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
	: type("Animal")
{
}

Animal::Animal( const Animal& animal )
{
	*this = animal;
}

Animal::~Animal()
{
}

Animal&	Animal::operator=( const Animal& animal )
{
	if (this != &animal)
		this->type = animal.type;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << "Undefined sounds 🎶" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
