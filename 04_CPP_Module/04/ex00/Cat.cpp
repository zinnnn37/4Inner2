/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:17:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->_type = "Cat";
}

Cat::Cat( const Cat& cat )
{
	*this = cat;
}

Cat::~Cat()
{
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
