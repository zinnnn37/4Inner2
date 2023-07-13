/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:28:35 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:19:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
	: WrongAnimal()
{
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& cat )
{
	*this = cat;
}

WrongCat::~WrongCat()
{
}

WrongCat&	WrongCat::operator=( const WrongCat& cat )
{
	if (this != &cat)
		this->_type = cat._type;

	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Cat Meows 🐱" << std::endl;
}
