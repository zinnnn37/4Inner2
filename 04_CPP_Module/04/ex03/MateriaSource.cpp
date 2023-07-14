/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:47:15 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 17:21:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#define BLUE "\033[0;34m"

MateriaSource::MateriaSource()
	: _cnt(0)
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

	this->_cnt = ms._cnt;

	for (int i = 0; i < 4; i++)
	{
		tmp = ms.getMateria(i);

		if (tmp)
			this->_materia[i] = tmp->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for ( int i = 0; i < 4; i++ )
	{
		if (this->_materia[i])
		{
			delete this->_materia[i];
			this->_materia[i] = NULL;
		}
	}

	std::cout << BLUE"[ MateriaSource Destructor ]" << std::endl;
	std::cout << WHITE"MateriaSource is destroyed\n" << std::endl;
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& ms )
{
	std::cout << BLUE"[ MateriaSource Assignation Operator ]\n" << std::endl;

	const AMateria*	tmp;

	if (this != &ms)
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( this->_materia[i] )
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

	if (!m)
	{
		std::cout << WHITE"Failed to Learn Materia: empty materia\n" << std::endl;
		return ;
	}
	if ( this->_cnt < 4 )
	{
		for ( int i = 0; i < 4; i++ )
		{
			if ( this->_materia[i] == NULL )
			{
				std::cout << WHITE"Succeed to Learn Materia\n" << std::endl;
				this->_materia[i] = m;
				this->_cnt++;

				break ;
			}
		}
	}
	else
		std::cout << WHITE"Failed to Learn Materia: slot is full\n" << std::endl;
}

AMateria*	MateriaSource::createMateria( std::string const &type )
{
	std::cout << BLUE"[ Create Materia ]" << std::endl;
	std::cout << WHITE"Creating " << type << std::endl;

	for ( int i = 0; i < 4; i++ )
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
