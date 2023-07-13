/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:23:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	std::cout << "🐱 Cat default constructor 🐱" << std::endl;

	this->_type = "Cat";
}

Cat::Cat( const Cat& cat )
{
	std::cout << "🐱 Cat copy constructor 🐱" << std::endl;

	*this = cat;
}

Cat::~Cat()
{
	std::cout << "🐱 Cat Destructor 🐱" << std::endl;
}

Cat&	Cat::operator=( const Cat& cat )
{
	if (this != &cat)
		this->_type = cat._type;

	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow 🐱" << std::endl;
}
