/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:39:02 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 23:32:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << YELLOW"[ Default Constructor ]\n";
	std::cout << WHITE"ScavTrap < default > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_name = "default";
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap( const std::string name )
{
	std::cout << YELLOW"[ Constructor ]\n";
	std::cout << WHITE"ScavTrap < " << name << " > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_name = name;
	this->_hit = 100;
	this->_energy = 50;
	this->_damage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& st )
	: ClapTrap(st)
{
	std::cout << YELLOW"[ Copy Constructor ]\n";
	std::cout << WHITE"ScavTrap < " << st._name << " > has been copied\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	*this = st;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW"[ Destructor ]\n";
	std::cout << WHITE"ScavTrap < " << this->_name << " > has gone\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
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
	std::cout << YELLOW"[ Attack ]\n";
	std::cout << WHITE"ScavTrap < " << this->_name << " > ";
	std::cout << "tries to attack < " << target << " >\n";

	if (this->_energy == 0)
	{
		std::cout << "▶︎ Out of energy! Fail to attack!\n\n";
		std::cout << "----------------------------------------------------------\n" << std::endl;
		return ;
	}
	else if (this->_hit <= 0)
	{
		std::cout << "▶︎ Out of hits! Fail to attack!\n\n";
		std::cout << "----------------------------------------------------------\n" << std::endl;
		return ;
	}

	std::cout << "▶︎ < " << target << " > got < " << this->_damage;
	std::cout << " > points of damage!\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_energy--;
}

void	ScavTrap::guardGate()
{
	std::cout << YELLOW"[ Guarding ]\n";

	std::cout << WHITE"ScavTrap < " << this->_name << " > is keeping the Gate\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
}

unsigned int	ScavTrap::getAttackDamage() const
{
	return (this->_damage);
}