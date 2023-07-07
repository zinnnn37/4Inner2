/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:26:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 16:43:31 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	std::cout << WHITE"[ 🐶::Constructor ]" << std::endl;

	this->brain = new Brain();

	this->type = "Dog";
}

Dog::Dog( const Dog& dog )
{
	*this = dog;
}

Dog::~Dog()
{
	std::cout << WHITE"[ 🐶::Destructor ]" << std::endl;

	delete this->brain;
}

Dog&	Dog::operator=( const Dog& dog )
{
	if (this != &dog)
		this->type = dog.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << WHITE"Woof 🐶" << std::endl;
}
