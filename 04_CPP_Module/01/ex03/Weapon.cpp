/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:18:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/07 14:56:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
}

Weapon::~Weapon()
{
	
}

const std::string&	Weapon::getType( void ) const
{
	return (this->_type);
}

void	Weapon::setType( std::string type )
{
	this->_type = type;
}