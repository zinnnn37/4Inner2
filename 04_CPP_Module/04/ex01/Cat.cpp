/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:18:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat& cat )
{
	this->_type = cat._type;
	this->_brain = new Brain(*cat._brain);
}

Cat::~Cat()
{
	delete this->_brain;
}

Cat&	Cat::operator=( const Cat& cat )
{
	if (this != &cat)
	{
		this->_type = cat._type;
		
		if (this->_brain)
			delete this->_brain;

		this->_brain = new Brain(*cat._brain);
	}

	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow 🐱" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return ( this->_brain );
}
