/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:43 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 18:35:45 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
	: AMateria("Cure")
{
	std::cout << GREEN"[ Cure Default Constructor ]" << WHITE << std::endl;
}

Cure::Cure( const Cure& cure )
	: AMateria(cure)
{
	std::cout << GREEN"[ Cure Copy Constructor ]" << WHITE << std::endl;

	this->_type = cure._type;
}

Cure::~Cure()
{
	std::cout << GREEN"[ Cure Destructor ]" << WHITE << std::endl;
}

Cure&	Cure::operator=( const Cure& cure )
{
	std::cout << GREEN"[ Cure Copy Assignment Operator ]" << WHITE << std::endl;

	if (this != &cure)
		this->_type = cure._type;

	return (*this);
}

AMateria*	Cure::clone() const
{
	return ( new Cure(*this) );
}

void	Cure::use( ICharacter& target )
{
	std::cout << GREEN"[ Heal ]\n" << WHITE << std::endl;

	std::cout << " * heals " << target.getName() << "'s wounds *" << std::endl;
}