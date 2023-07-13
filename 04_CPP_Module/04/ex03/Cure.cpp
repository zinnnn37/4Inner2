/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:29:43 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 00:44:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure()
	: AMateria("Cure")
{
	std::cout << GREEN"[ Cure Default Constructor ]" << WHITE << std::endl;
	std::cout << WHITE"Cure is created\n" << std::endl;
}

Cure::Cure( const std::string &type )
	: AMateria(type)
{
	std::cout << GREEN"[ Cure Constructor: type ]" << WHITE << std::endl;
	std::cout << WHITE"Cure is created\n" << std::endl;
}

Cure::Cure( const Cure& cure )
	: AMateria(cure)
{
	std::cout << GREEN"[ Cure Copy Constructor ]" << WHITE << std::endl;
	std::cout << WHITE"Cure is created\n" << std::endl;
}

Cure::~Cure()
{
	std::cout << GREEN"[ Cure Destructor ]" << WHITE << std::endl;
	std::cout << WHITE"Cure is destroyed\n" << std::endl;
}

Cure&	Cure::operator=( const Cure& cure )
{
	std::cout << GREEN"[ Cure Copy Assignment Operator ]\n" << WHITE << std::endl;

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
	std::cout << GREEN"[ Heal ]\n" << std::endl;

	std::cout << WHITE" * heals " << target.getName() << "'s wounds *" << std::endl;
}