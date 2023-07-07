/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:26:36 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 11:53:02 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	: Animal()
{
	this->type = "Dog";
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
	this->type = dog.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof 🐶" << std::endl;
}
