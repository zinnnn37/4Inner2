/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 11:53:06 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->type = "Cat";
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
	this->type = cat.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow 🐱" << std::endl;
}
