/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:26:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:19:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog( const Dog& dog )
{
	this->_type = dog._type;
	this->_brain = new Brain(*dog._brain);
}

Dog::~Dog()
{
	delete this->_brain;
}

Dog&	Dog::operator=( const Dog& dog )
{
	if (this != &dog)
	{
		this->_type = dog._type;
		
		if (this->_brain)
			delete this->_brain;

		this->_brain = new Brain(*dog._brain);
	}

	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof 🐶" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return ( this->_brain );
}
