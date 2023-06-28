/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:41:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/28 15:52:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << GREEN"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"FragTrap < default > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	this->_name = "default";
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap( const std::string name )
{
	std::cout << GREEN"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"FragTrap < " << name << " > has been created" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	this->_name = name;
	this->_hit = 100;
	this->_energy = 100;
	this->_damage = 30;
}

FragTrap::FragTrap( const FragTrap& ft )
{
	std::cout << GREEN"[ Copy Constructor ]" << std::endl;
	std::cout << WHITE"FragTrap < " << ft._name << " > has been copied" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;

	*this = ft;
}

FragTrap::~FragTrap()
{
	std::cout << GREEN"[ Destructor ]" << std::endl;
	std::cout << WHITE"FragTrap < " << this->_name << " > has gone" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
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
	std::cout << GREEN"[ High Five ]" << std::endl;

	std::cout << WHITE"FragTrap < " << this->_name << " > is requesting high-five!" << std::endl << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl << std::endl;
}

unsigned int	FragTrap::getAttackDamage() const
{
	return (this->_damage);
}