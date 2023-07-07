/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:56 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 16:21:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	: Animal()
{
	std::cout << WHITE"[ 🐱::Constructor ]" << std::endl;

	this->brain = new Brain();

	this->type = "Cat";
}

Cat::Cat( const Cat& cat )
{
	*this = cat;
}

Cat::~Cat()
{
	std::cout << WHITE"[ 🐱::Destructor ]" << std::endl;

	delete this->brain;
}

Cat&	Cat::operator=( const Cat& cat )
{
	this->type = cat.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << WHITE"Meow 🐱" << std::endl;
}

Brain*	Cat::getbrain() const
{
	return ( this->brain );
}
