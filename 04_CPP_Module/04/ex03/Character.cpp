/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:46:33 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 19:05:49 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("default"), _idx(0)
{
	std::cout << YELLOW"[ Default Constructor ]" << WHITE << std::endl;

	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character( std::string name )
	: _name(name), _idx(0)
{
	std::cout << YELLOW"[ Constructor: name ]" << WHITE << std::endl;

	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Characcter( const Character &c )
{
	std::cout << YELLOW"[ Copy Constructor ]" << WHITE << std::endl;

	*this = c;
}

Character::~Character()
{
	std::cout << YELLOW"[ Destructor ]" << WHITE << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if ( this->_slot[i] )
			delete (this->_slot[i]);
	}
}

Character&	Character::operator=( const Character &c )
{
	std::cout << YELLOW"[ Copy Assignment Operator ]" << WHITE << std::endl;

	if (this != &c)
	{
		this->_name = c._name;
		this->_idx = c._idx;

		for (int i = 0; i < 4; i++)
		{
			if ( this->_slot[i] )
				delete this->_slot[i];
			this->_slot[i] = c._slot[i];
		}
	}

	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equipe( AMateria* m )
{
	std::cout << YELLOW"[ Equip Skill ]" << WHITE << std::endl;

	if ( this->_idx < 4 )
	{
		std::cout << " * " << this->_name << " equiped " << m->getType() << " *" << std::endl;
		this->_slot[this->_idx] = m->clone();
		this->_idx++;
	}
	else
		std::cout << "* Out of slots *" << std::endl;
}