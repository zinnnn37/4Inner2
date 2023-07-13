/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:34:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
	: len(0)
{
	std::cout << "🧠 Brain default constructor 🧠" << std::endl;
}

Brain::Brain( const Brain& brain )
{
	std::cout << "🧠 Brain copy constructor 🧠" << std::endl;

	*this = brain;
}

Brain::~Brain()
{
	std::cout << "🧠 Brain destructor 🧠" << std::endl;
}

Brain&	Brain::operator=( const Brain& brain )
{
	if (this != &brain)
	{
		this->len = brain.len;
		for (int i = 0; i < brain.len; i++)
			this->ideas[i] = brain.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdea( int idx ) const
{
	std::cout << WHITE"getIdea: ";

	if ( idx < 0 || idx >= this->len )
		return (RED"Index out of range");
	
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
