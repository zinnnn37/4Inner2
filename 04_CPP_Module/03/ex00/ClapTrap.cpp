/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/27 06:21:55 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("default"), _hit(10), _energy(10), _damage(0)
{
	std::cout << CYAN"[ Default Constructor ]" << std::endl;
	std::cout << WHITE"< default > has been created" << std::endl << std::endl;
}

ClapTrap::ClapTrap( const std::string& name )
	: _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << CYAN"[ Constructor ]" << std::endl;
	std::cout << WHITE"< " << this->_name << " > has been created" << std::endl << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& ct )
{
	std::cout << CYAN"[ Copy Constructor ]" << std::endl;
	std::cout << WHITE"< " << this->_name << " > has been copied" << std::endl << std::endl;

	*this = ct;
}

ClapTrap::~ClapTrap()
{
	std::cout << CYAN"[ Destructor ]" << std::endl;
}

void	ClapTrap::_print()
{
	std::cout << GREEN"NAME\t\t: " << this->_name << std::endl;
	std::cout << "HIT POINTS\t: " << this->_hit << std::endl;
	std::cout << "ENERGY POINTS\t: " << this->_energy << std::endl;
	std::cout << "ATTACK DAMAGE\t: " << this->_damage << std::endl << std::endl;
}