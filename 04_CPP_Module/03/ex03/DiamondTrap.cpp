/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:03:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 16:21:07 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
}

DiamondTrap::DiamondTrap( const std::string name )
{
	std::cout << PURPLE"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"DiamondTrap < " << name << " > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	this->_name = ClapTrap::_name.append(name);
	this->_hit = FragTrap::_hit;
}

DiamondTrap::DiamondTrap( const DiamondTrap& dt )
{
	*this = dt;
}

DiamondTrap::~DiamondTrap()
{
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& dt )
{
	if (this == &dt)
		return *this;

	this->_name = dt._name;
	this->_hit = dt._hit;
	this->_energy = dt._energy;
	this->_damage = dt._damage;

	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << PURPLE"[ Who Am I ]" << std::endl;
	
	std::cout << WHITE"DiamondTrap < " << this->_name << " > is ClapTrap < ";
	std::cout << ClapTrap::getName() << " >\n\n";
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}
