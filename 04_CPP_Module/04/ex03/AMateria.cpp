/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:23:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 00:52:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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

void	AMateria::use( const ICharacter& c)
{
	std::cout << PURPLE"[ Use ]" << WHITE << std::endl;
	std::cout << c.getName() << " is using skill\n" << std::endl;
}