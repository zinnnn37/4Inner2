/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 16:43:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
	: len(0)
{
	std::cout << WHITE"[ 🧠::Constructor ]" << std::endl;
}

Brain::Brain( const Brain& brain )
{
	*this = brain;
}

Brain::~Brain()
{
	std::cout << WHITE"[ 🧠::Destructor ]" << std::endl;
}

Brain&	Brain::operator=( const Brain& brain )
{
	if (this != &brain)
	{
		this->len = brain.len;
		for (int i = 0; i < 100; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea( int idx ) const
{
	std::cout << WHITE"getIdea: ";

	if ( idx < 0 || idx >= this->len )
		return (RED"💥 Index out of range! 💥");
	
	return (this->ideas[idx]);
}

void	Brain::setIdea( std::string idea )
{
	if ( this->len >= 100 )
	{
		std::cout << RED"Out of storage!" << std::endl;
		return ;
	}

	this->ideas[this->len] = idea;
	this->len++;
}
// deepcopy 확인
