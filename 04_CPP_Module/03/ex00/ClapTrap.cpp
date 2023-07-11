/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 23:35:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), _hit(10), _energy(10), _damage(0)
{
	std::cout << CYAN"[ Default Constructor ]\n";
	std::cout << WHITE"ClapTrap < default > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
	: _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << CYAN"[ Constructor ]\n";
	std::cout << WHITE"ClapTrap < " << this->_name << " > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& ct )
{
	std::cout << CYAN"[ Copy Constructor ]\n";
	std::cout << WHITE"ClapTrap < " << ct._name << " > has been copied\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	*this = ct;
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN"[ Destructor ]\n";
	std::cout << WHITE"ClapTrap < " << this->_name << " > has gone\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
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
	std::cout << CYAN"[ Attack ]\n";
	std::cout << WHITE"ClapTrap < " << this->_name << " > ";
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

void	ClapTrap::takeDamage( unsigned int amount )
{
	std::cout << CYAN"[ Take Damage ]\n";

	std::cout << WHITE"▶︎ ClapTrap < " << this->_name << " > got < ";
	std::cout << amount << " > points of damage!\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_hit -= amount;

	if ( this->_hit < 0 )
		this->_hit = 0;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	std::cout << CYAN"[ Reparing ]\n";

	std::cout << WHITE"ClapTrap < " << this->_name << " > is repairing\n";
	
	if (this->_energy == 0)
	{
		std::cout << "▶︎ Out of energy! Fail to repair!\n\n";
		std::cout << "----------------------------------------------------------\n" << std::endl;
		return ;
	}
	else if (this->_hit <= 0)
	{
		std::cout << "▶︎ Out of hits! Fail to repair!\n\n";
		std::cout << "----------------------------------------------------------\n" << std::endl;
		return ;
	}

	std::cout << "▶︎ ClapTrap < " << this->_name << " > got < ";
	std::cout << amount << " > points of Hits!\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
	this->_hit += amount;
	this->_energy--;
}

void	ClapTrap::print()
{
	std::cout << CYAN"========================< STATUS >========================\n\n";
	std::cout << "\t\t   NAME\t\t  : " << this->_name << '\n';
	std::cout << "\t\t   HIT POINTS     : " << this->_hit << '\n';
	std::cout << "\t\t   ENERGY POINTS  : " << this->_energy << '\n';
	std::cout << "\t\t   ATTACK DAMAGE  : " << this->_damage << "\n\n";
	std::cout << "==========================================================\n\n";
	std::cout << WHITE"----------------------------------------------------------\n" << std::endl;
}
