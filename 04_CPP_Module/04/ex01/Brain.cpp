/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:43:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/06 14:49:21 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
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
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];

	return (*this);
}
// deepcopy 확인
