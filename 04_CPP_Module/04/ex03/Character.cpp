/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:46:33 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/16 13:36:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("default"), _cnt(0)
{
	std::cout << PURPLE"[ Character Default Constructor ]" << WHITE << std::endl;
	std::cout << this->_name << " is created\n" << std::endl;

	for ( int i = 0; i < 4; i++ )
		this->_slot[i] = NULL;
}

Character::Character( std::string name )
	: _name(name), _cnt(0)
{
	std::cout << PURPLE"[ Character Constructor: name ]" << WHITE << std::endl;
	std::cout << this->_name << " is created\n" << std::endl;

	for ( int i = 0; i < 4; i++ )
		this->_slot[i] = NULL;
}

Character::Character( const Character &c )
	: _name(c._name), _cnt(c._cnt)
{
	std::cout << PURPLE"[ Character Copy Constructor ]" << WHITE << std::endl;
	std::cout << this->_name << " is copied\n" << std::endl;

	const AMateria*	tmp;

	for ( int i = 0; i < 4; i++ )
	{
		tmp = c.getMateria(i);

		if (tmp)
			this->_slot[i] = tmp->clone();
		else
			this->_slot[i] = NULL;
	}
}

Character::~Character()
{
	for ( int i = 0; i < 4; i++ )
	{
		if ( this->_slot[i] )
		{
			delete this->_slot[i];
			this->_slot[i] = NULL;
		}
	}

	std::cout << PURPLE"[ Character Destructor ]" << WHITE << std::endl;
	std::cout << this->_name << " is gone\n" << std::endl;
}

Character&	Character::operator=( const Character &c )
{
	std::cout << PURPLE"[ Character Copy Assignment Operator ]\n" << WHITE << std::endl;

	if ( this != &c )
	{
		const AMateria*	tmp;

		this->_name = c._name;
		this->_cnt = c._cnt;

		for ( int i = 0; i < 4; i++ )
		{
			if ( this->_slot[i] != NULL )
				delete this->_slot[i];
			
			tmp = c.getMateria(i);

			if (tmp)
				this->_slot[i] = tmp->clone();
			else
				this->_slot[i] = NULL;
		}
	}

	return *this;
}

std::string const	&Character::getName() const
{
	return this->_name;
}

void	Character::equip( AMateria* m )
{
	std::cout << PURPLE"[ Character Equip ]" << WHITE << std::endl;

	if ( !m )
	{
		std::cout << "Empty materia\n" << std::endl;
		return ;
	}
	if ( this->_cnt < 4 )
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( this->_slot[i] == NULL )
			{
				std::cout << this->_name << " equiped " << m->getType() << "\n" << std::endl;
				this->_slot[i] = m->clone();
				this->_cnt++;

				break ;
			}
		}
	}
	else
		std::cout << "Out of slots\n" << std::endl;
}

void	Character::unequip( int idx )
{
	std::cout << PURPLE"[ Character Unequip ]" << WHITE << std::endl;

	if ( idx < 0 || idx > 3 )
		return ;

	if ( this->_slot[idx] )
	{
		std::cout << this->_name << " unequiped " << this->_slot[idx]->getType() << "\n" << std::endl;
		
		this->_slot[idx] = NULL;
		this->_cnt--;
	}
	else
		std::cout << "Empty slot\n" << std::endl;
}

void	Character::use( int idx, const ICharacter& ic )
{
	std::cout << PURPLE"[ Character Use ]" << WHITE << std::endl;
	std::cout << this->_name << " used " << this->_slot[idx]->getType() << "\n" << std::endl;

	if ( idx < 0 || idx > 3 )
		return ;

	if ( this->_slot[idx] )
		this->_slot[idx]->use(ic);
	else
		std::cout << "Empty slot\n" << std::endl;
}

const AMateria*	Character::getMateria( int idx ) const
{
	return ( this->_slot[idx] );
}
