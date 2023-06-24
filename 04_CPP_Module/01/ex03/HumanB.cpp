/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:46:35 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/07 14:56:00 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name )
{
	this->_name = name;
	this->_weapon = NULL;
}

HumanB::~HumanB()
{
	
}

void	HumanB::attack( void ) const
{
	std::cout << this->_name << " attacked with ";
	if (this->_weapon)
		std::cout << this->_weapon->getType() << std::endl;	// pointer
	else
		std::cout << "nothing" << std::endl;	// pointer
}

void	HumanB::setWeapon( Weapon &weapon )
{
	this->_weapon = &weapon;
}