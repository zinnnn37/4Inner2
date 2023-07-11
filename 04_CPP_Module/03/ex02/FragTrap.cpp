/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:41:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 23:46:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GREEN"[ Default Constructor ]\n";
	std::cout << WHITE"FragTrap < default > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_name = "default";
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap( const std::string name )
{
	std::cout << GREEN"[ Default Constructor ]\n";
	std::cout << WHITE"FragTrap < " << name << " > has been created\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	this->_name = name;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap( const FragTrap& ft )
	: ClapTrap(ft)
{
	std::cout << GREEN"[ Copy Constructor ]\n";
	std::cout << WHITE"FragTrap < " << ft._name << " > has been copied\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;

	*this = ft;
}

FragTrap::~FragTrap()
{
	std::cout << GREEN"[ Destructor ]\n";
	std::cout << WHITE"FragTrap < " << this->_name << " > has gone\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& ft )
{
	if (this == &ft)
		return *this;
	
	this->_name = ft._name;
	this->_hit = ft._hit;
	this->_damage = ft._damage;
	this->_energy = ft._energy;

	return *this;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << GREEN"[ High Five ]\n";

	std::cout << WHITE"FragTrap < " << this->_name << " > is requesting high-five!\n\n";
	std::cout << "----------------------------------------------------------\n" << std::endl;
}

unsigned int	FragTrap::getAttackDamage() const
{
	return (this->_damage);
}