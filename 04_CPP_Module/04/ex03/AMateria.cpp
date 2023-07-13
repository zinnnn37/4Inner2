/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:23:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 23:17:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria()
	: _type("default")
{
	std::cout << PURPLE"[ Default Constructor ]\n" << WHITE << std::endl;
}

AMateria::AMateria( std::string const &type )
	: _type(type)
{
	std::cout << PURPLE"[ Constructor: type ]\n" << WHITE << std::endl;
}

AMateria::AMateria( const AMateria& a )
{
	std::cout << PURPLE"[ Copy Constructor ]\n" << WHITE << std::endl;

	this->_type = a._type;
}

AMateria::~AMateria()
{
	std::cout << PURPLE"[ Destructor ]\n" << WHITE << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& a )
{
	std::cout << PURPLE"[ Copy Assignment Operator ]" << WHITE << std::endl;

	if (this != &a)
		this->_type = a.getType();

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
	std::cout << "Use Skill of " << target.getName() << "\n" << std::endl;
}