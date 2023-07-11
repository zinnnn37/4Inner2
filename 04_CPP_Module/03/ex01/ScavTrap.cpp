/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:39:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 14:33:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << YELLOW"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"ScavTrap < default > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	this->_name = "default";
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap( const std::string name )
{
	std::cout << YELLOW"[ Constructor ]" << std::endl;
	std::cout << WHITE"ScavTrap < " << name << " > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	this->_name = name;
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& ct )
{
	std::cout << YELLOW"[ Copy Constructor ]" << std::endl;
	std::cout << WHITE"ScavTrap < " << ct._name << " > has been copied" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	*this = ct;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW"[ Destructor ]" << std::endl;
	std::cout << WHITE"ScavTrap < " << this->_name << " > has gone" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& ct )
{
	if (this == &ct)
		return *this;
	
	this->_name = ct._name;
	this->_hit = ct._hit;
	this->_damage = ct._damage;
	this->_energy = ct._energy;

	return *this;
}

void	ScavTrap::attack( const std::string& target )
{
	std::cout << YELLOW"[ Attack ]" << std::endl;
	std::cout << WHITE"ScavTrap < " << this->_name << " > ";
	std::cout << "tries to attack < " << target << " >" << std::endl;

	if (this->_energy == 0)
	{
		std::cout << RED"▶︎ Out of energy! Fail to attack!" << std::endl << std::endl;
		std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;
		return ;
	}
	else if (this->_hit <= 0)
	{
		std::cout << RED"▶︎ Out of hits! Fail to attack!" << std::endl << std::endl;
		std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;
		return ;
	}

	std::cout << RED"▶︎ < " << target << " > got < " << this->_damage;
	std::cout << " > points of damage!" << std::endl << std::endl;
	std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;

	this->_energy--;
}

void	ScavTrap::guardGate()
{
	std::cout << YELLOW"[ Guarding ]" << std::endl;

	std::cout << WHITE"ScavTrap < " << this->_name << " > is in Gate keeper mode" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

unsigned int	ScavTrap::getAttackDamage() const
{
	return (this->_damage);
}