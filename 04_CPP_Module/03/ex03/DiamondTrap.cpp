/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 14:03:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/12 14:17:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << PURPLE"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"DiamondTrap < default > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_name = "default";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_damage = 30;
}

DiamondTrap::DiamondTrap( const std::string name )
	: ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	std::cout << PURPLE"[ Constructor: name ]" << std::endl;
	std::cout << WHITE"DiamondTrap < " << name << " > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_damage = 30;
}

DiamondTrap::DiamondTrap( const DiamondTrap& dt )
	: ClapTrap(dt), FragTrap(dt), ScavTrap(dt)
{
	std::cout << PURPLE"[ Copy Constructor ]" << std::endl;
	std::cout << WHITE"DiamondTrap < " << this->_name << " > has been copied\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
	
	*this = dt;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << PURPLE"[ Destructor ]" << std::endl;
	std::cout << WHITE"DiamondTrap < " << _name << " > has gone\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
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
	std::cout << ClapTrap::_name << " >\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
}
