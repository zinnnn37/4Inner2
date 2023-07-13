/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:26:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:17:51 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->_type = "Dog";
}

Dog::Dog( const Dog& dog )
{
	*this = dog;
}

Dog::~Dog()
{
}

Dog&	Dog::operator=( const Dog& dog )
{
	if (this != &dog)
		this->_type = dog._type;

	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof 🐶" << std::endl;
}
