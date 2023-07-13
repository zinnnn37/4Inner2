/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:23:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 18:35:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	: _type("default")
{
	std::cout << PURPLE"[ Default Constructor ]" << WHITE << std::endl;
}

AMateria::AMateria( std::string const &type )
	: _type(type)
{
	std::cout << PURPLE"[ Constructor: type ]" << WHITE << std::endl;
}

AMateria::AMateria( const AMateria& a )
{
	std::cout << PURPLE"[ Copy Constructor ]" << WHITE << std::endl;

	this->_type = a._type;
}

AMateria::~AMateria()
{
	std::cout << PURPLE"[ Destructor ]" << WHITE << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& a )
{
	std::cout << PURPLE"[ Copy Assignment Operator ]" << WHITE << std::endl;

	if (this != &a)
		this->_type = a._type;

	return (*this);
}

std::string const &AMateria::getType() const
{
	return ( this->_type );
}

AMateria*	AMateria::clone() const
{
	return ( new AMateria(*this));
}

void	AMateria::use( ICharacter& target)
{
	std::cout << PURPLE"[ Skill ]" << WHITE << std::endl;

	(void)target;
}