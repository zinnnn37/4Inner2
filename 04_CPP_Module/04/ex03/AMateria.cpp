/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:23:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 11:13:59 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
	: _type("default")
{
	std::cout << PURPLE"[ AMateria Default Constructor ]\n" << WHITE << std::endl;
}

AMateria::AMateria( std::string const &type )
	: _type(type)
{
	std::cout << PURPLE"[ AMateria Constructor: type ]\n" << WHITE << std::endl;
}

AMateria::AMateria( const AMateria& a )
{
	std::cout << PURPLE"[ AMateria Copy Constructor ]\n" << WHITE << std::endl;

	this->_type = a._type;
}

AMateria::~AMateria()
{
	std::cout << PURPLE"[ AMateria Destructor ]\n" << WHITE << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& a )
{
	std::cout << PURPLE"[ AMateria Copy Assignment Operator ]" << WHITE << std::endl;

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
	std::cout << PURPLE"[ AMateria Use ]" << WHITE << std::endl;
	std::cout << c.getName() << " is using skill\n" << std::endl;
}