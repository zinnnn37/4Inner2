/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:34:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 12:23:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

#define CYAN "\033[36m"

Ice::Ice()
	: AMateria("ice")
{
	std::cout << CYAN"[ Ice Default Constructor ]" << std::endl;
	std::cout << WHITE"Ice is created\n" << std::endl;
}

Ice::Ice( const Ice &ice )
	: AMateria(ice)
{
	std::cout << CYAN"[ Ice Copy Constructor ]" << std::endl;
	std::cout << WHITE"Ice is copied\n" << std::endl;
}

Ice::~Ice()
{
	std::cout << CYAN"[ Ice Destructor ]" << std::endl;
	std::cout << WHITE"Ice is destroyed\n" << std::endl;
}

Ice&	Ice::operator=( const Ice &ice )
{
	std::cout << CYAN"[ Ice Copy Assignment Operator ]\n" << WHITE << std::endl;

	if (this != &ice)
		this->_type = ice.getType();

	return (*this);
}

AMateria*	Ice::clone() const
{
	return ( new Ice(*this) );
}

void	Ice::use( const ICharacter& c )
{
	std::cout << CYAN"[ Attack ]" << std::endl;
	std::cout << WHITE" * shoots an ice bolt at " << c.getName() << " *\n" << std::endl;
}
