/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:26:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 13:47:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	std::cout << "🐶 Dog default constructor 🐶" << std::endl;

	this->_type = "Dog";
}

Dog::Dog( const Dog& dog )
{
	std::cout << "🐶 Dog copy constructor 🐶" << std::endl;

	*this = dog;
}

Dog::~Dog()
{
	std::cout << "🐶 Dog Destructor 🐶" << std::endl;
}

Dog&	Dog::operator=( const Dog& dog )
{
	if (this != &dog)
		this->_type = dog.getType();

	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof 🐶" << std::endl;
}
