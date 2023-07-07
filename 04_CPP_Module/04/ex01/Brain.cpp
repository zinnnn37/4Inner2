/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 13:57:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
	: len(0)
{
}

Brain::Brain( const Brain& brain )
{
	*this = brain;
}

Brain::~Brain()
{
}

Brain&	Brain::operator=( const Brain& brain )
{
	this->len = brain.len;
	
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];

	return (*this);
}

std::string	Brain::getIdea( int idx ) const
{
	if ( idx < 0 || idx >= this->len )
	{
		std::cout << "Index out of range!" << std::endl;
		return ;
	}
	
	return (this->ideas[idx]);
}

void	Brain::setIdea( std::string idea )
{
	if ( this->len >= 100 )
	{
		std::cout << "Out of storage!" << std::endl;
		return ;
	}
	
	this->ideas[this->len] = idea;
	this->len++;
}
// deepcopy 확인
