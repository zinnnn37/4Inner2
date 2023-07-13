/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 18:36:47 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << CYAN"[ Ice Default Constructor ]" << WHITE << std::endl;
}

Ice::Ice( const Ice &ice )
	: AMateria(ice)
{
	std::cout << CYAN"[ Ice Copy Constructor ]" << WHITE << std::endl;

	this->_type = ice._type;
}

Ice::~Ice()
{
	std::cout << CYAN"[ Ice Destructor ]" << WHITE << std::endl;
}

Ice&	Ice::operator=( const Ice &ice )
{
	std::cout << CYAN"[ Ice Copy Assignment Operator ]" << WHITE << std::endl;

	if (this != &ice)
		this->_type = ice._type;

	return (*this);
}

AMateria*	Ice::clone() const
{
	return ( new Ice(*this) );
}

void	Ice::use( ICharacter& target )
{
	std::cout << CYAN"[ Attack ]\n" << WHITE << std::endl;

	std::cout << " * shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
