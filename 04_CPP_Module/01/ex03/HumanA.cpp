/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 10:53:00 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/24 11:09:48 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon )
	: _name(name), _weapon(weapon)
{
}


HumanA::~HumanA()
{
}

void	HumanA::attack( void ) const
{
	std::cout << this->_name << " attacked with ";
	std::cout << this->_weapon.getType() << std::endl;
}