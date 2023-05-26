/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:13:15 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/26 13:18:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	this->_name = "default";
}

Zombie::Zombie( std::string name )
{
	this->_name = name;
}

Zombie::~Zombie( void )
{
	std::cout << "<" << this->_name << "> is dead" << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->_name = name;
}

void Zombie::announce( int i )
{
	std::cout << "<" << this->_name << " " << i + 1;
	std::cout << "> BraiiiiiiinnnzzzZ..." << std::endl;
}
