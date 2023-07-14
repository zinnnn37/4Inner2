/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:47:15 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 11:15:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#define BLUE "\033[0;34m"

MateriaSource::MateriaSource()
	: _idx(0)
{
	std::cout << BLUE"[ MateriaSource Default Constructor ]" << std::endl;
	std::cout << WHITE"MateriaSource is created\n" << std::endl;

	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource &ms )
{
	std::cout << BLUE"[ MateriaSource Copy Constructor ]" << std::endl;
	std::cout << WHITE"MateriaSource is copied\n" << std::endl;

	const AMateria*	tmp;

	this->_idx = ms._idx;

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
		
		tmp = ms.getMateria(i);

		if (tmp)
			this->_materia[i] = tmp->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << BLUE"[ MateriaSource Destructor ]" << std::endl;
	std::cout << WHITE"MateriaSource is destroyed\n" << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i])
			delete this->_materia[i];
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& ms )
{
	std::cout << BLUE"[ MateriaSource Assignation Operator ]\n" << std::endl;

	const AMateria*	tmp;

	if (this != &ms)
	{
		for ( int i = 0; i < 4; i++ )
		{
			if (this->_materia[i])
				delete this->_materia[i];
			
			tmp = ms.getMateria(i);

			if (tmp)
				this->_materia[i] = tmp->clone();
			else
				this->_materia[i] = NULL;
		}
	}

	return ( *this );
}

void	MateriaSource::learnMateria( AMateria* m )
{
	std::cout << BLUE"[ Learn Materia ]" << std::endl;
	std::cout << WHITE"Learning " << m->getType() << std::endl;

	if (this->_idx < 4)
	{
		std::cout << WHITE"Succeed to Learn Materia\n" << std::endl;

		this->_materia[this->_idx] = m;
		this->_idx++;
	}
	else
		std::cout << WHITE"Failed to Learn Materia: slot is full\n" << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const &type )
{
	std::cout << BLUE"[ Create Materia ]" << std::endl;
	std::cout << WHITE"Creating " << type << std::endl;

	for (int i = 0; i < 4; i++)
	{
		if ( this->_materia[i] && type.compare(this->_materia[i]->getType()) == 0 )
		{
			std::cout << WHITE"Succeed to Create Materia\n" << std::endl;

			return this->_materia[i]->clone();
		}
	}

	std::cout << WHITE"Failed to Create Materia: no matched type\n" << std::endl;

	return NULL;
}

const AMateria*	MateriaSource::getMateria( int idx ) const
{
	return this->_materia[idx];
}
