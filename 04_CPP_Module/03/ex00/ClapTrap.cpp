/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 14:09:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), _hit(10), _energy(10), _damage(0)
{
	std::cout << CYAN"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"ClapTrap < default > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
	: _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << CYAN"[ Constructor ]" << std::endl;
	std::cout << WHITE"ClapTrap < " << this->_name << " > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& ct )
{
	std::cout << CYAN"[ Copy Constructor ]" << std::endl;
	std::cout << WHITE"ClapTrap < " << ct._name << " > has been copied" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	*this = ct;
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN"[ Destructor ]" << std::endl;
	std::cout << WHITE"ClapTrap < " << this->_name << " > has gone" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& ct )
{
	if (this == &ct)
		return *this;
	
	this->_name = ct._name;
	this->_hit = ct._hit;
	this->_damage = ct._damage;
	this->_energy = ct._energy;

	return *this;
}

void	ClapTrap::attack( const std::string& target )
{
	std::cout << CYAN"[ Attack ]" << std::endl;
	std::cout << WHITE"ClapTrap < " << this->_name << " > ";
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

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << CYAN"[ Take Damage ]" << std::endl;

	std::cout << RED"▶︎ ClapTrap < " << this->_name << " > got < ";
	std::cout << amount << " > points of damage!" << std::endl << std::endl;
	std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;

	this->_hit -= amount;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << CYAN"[ Reparing ]" << std::endl;

	std::cout << WHITE"ClapTrap < " << this->_name << " > is repairing" << std::endl;
	
	if (this->_energy == 0)
	{
		std::cout << RED"▶︎ Out of energy! Fail to repair!" << std::endl;
		std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;
		return ;
	}
	else if (this->_hit <= 0)
	{
		std::cout << RED"▶︎ Out of hits! Fail to repair!" << std::endl << std::endl;
		std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;
		return ;
	}

	std::cout << BLUE"▶︎ ClapTrap < " << this->_name << " > got < ";
	std::cout << amount << " > points of Hits!" << std::endl << std::endl;
	std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;

	this->_hit += amount;
	this->_energy--;
}

void	ClapTrap::print()
{
	std::cout << CYAN"========================< STATUS >========================" << std::endl << std::endl;
	std::cout << "\t\t   NAME\t\t  : " << this->_name << std::endl;
	std::cout << "\t\t   HIT POINTS     : " << this->_hit << std::endl;
	std::cout << "\t\t   ENERGY POINTS  : " << this->_energy << std::endl;
	std::cout << "\t\t   ATTACK DAMAGE  : " << this->_damage << std::endl << std::endl;
	std::cout << "==========================================================" << std::endl << std::endl;
	std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;
}
