/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:46:33 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 01:21:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("default"), _idx(0)
{
	std::cout << YELLOW"[ Default Constructor ]" << WHITE << std::endl;
	std::cout << this->_name << " is created\n" << std::endl;

	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character( std::string name )
	: _name(name), _idx(0)
{
	std::cout << YELLOW"[ Constructor: name ]" << WHITE << std::endl;
	std::cout << this->_name << " is created\n" << std::endl;

	for (int i = 0; i < 4; i++)
		this->_slot[i] = NULL;
}

Character::Character( const Character &c )
{
	std::cout << YELLOW"[ Copy Constructor ]" << WHITE << std::endl;
	std::cout << this->_name << " is copied\n" << std::endl;

	const AMateria*	tmp;

	this->_name = c._name;
	this->_idx = c._idx;

	for (int i = 0; i < 4; i++)
	{
		if ( this->_slot[i] )
			delete this->_slot[i];
		
		tmp = c.getMateria(i);

		if (tmp)
			this->_slot[i] = tmp->clone();
		else
			this->_slot[i] = NULL;
	}
}

Character::~Character()
{
	std::cout << YELLOW"[ Destructor ]" << WHITE << std::endl;
	std::cout << this->_name << " is gone\n" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if ( this->_slot[i] )
			delete (this->_slot[i]);
	}
}

Character&	Character::operator=( const Character &c )
{
	std::cout << YELLOW"[ Copy Assignment Operator ]\n" << WHITE << std::endl;

	if (this != &c)
	{
		const AMateria*	tmp;

		this->_name = c._name;
		this->_idx = c._idx;

		for (int i = 0; i < 4; i++)
		{
			if ( this->_slot[i] )
				delete this->_slot[i];
			
			tmp = c.getMateria(i);

			if (tmp)
				this->_slot[i] = tmp->clone();
			else
				this->_slot[i] = NULL;
		}
	}

	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip( AMateria* m )
{
	std::cout << YELLOW"[ Equip Materia ]" << WHITE << std::endl;

	if ( !m )
		return ;
	if ( this->_idx < 4 )
	{
		std::cout << this->_name << " equiped " << m->getType() << "\n" << std::endl;
		this->_slot[this->_idx] = m->clone();
		this->_idx++;
	}
	else
		std::cout << "Out of slots\n" << std::endl;
}

void	Character::unequip( int idx ) // not delete
{
	std::cout << YELLOW"[ Unequip Materia ]" << WHITE << std::endl;

	if ( idx < 0 || idx > 3 )
		return ;

	if ( this->_slot[idx] )
	{
		std::cout << this->_name << " unequiped " << this->_slot[idx]->getType() << "\n" << std::endl;
		
		this->_slot[idx] = NULL;
		this->_idx--;
	}
	else
		std::cout << "Empty slot\n" << std::endl;
}

void	Character::use( int idx, const ICharacter& c )
{
	std::cout << YELLOW"[ Use Materia ]" << WHITE << std::endl;
	std::cout << this->_name << " used " << this->_slot[idx]->getType() << "\n" << std::endl;

	if ( idx < 0 || idx > 3 )
		return ;

	if ( this->_slot[idx] )
		this->_slot[idx]->use(c);
	else
		std::cout << "Empty slot\n" << std::endl;
}

const AMateria*	Character::getMateria( int idx ) const
{
	return ( this->_slot[idx] );
}
