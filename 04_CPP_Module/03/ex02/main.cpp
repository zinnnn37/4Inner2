/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/27 15:58:41 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	std::cout << CYAN"==========================================================" << std::endl << std::endl;
	std::cout << "                         CLAPTRAP                        " << std::endl << std::endl;
	std::cout << "==========================================================" << std::endl << std::endl;
	std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;

	ScavTrap	a("A");
	ScavTrap	b("B");

	a.attack("B");
	b.takeDamage( a.getAttackDamage() );
	b.beRepaired(10);
	b.print();

	b.attack("A");
	a.takeDamage( a.getAttackDamage() );
	a.beRepaired(15);
	a.print();
	
	a.attack("B");
	b.takeDamage( a.getAttackDamage() );
	b.takeDamage( a.getAttackDamage() );
	b.takeDamage( a.getAttackDamage() );
	b.takeDamage( a.getAttackDamage() );
	b.takeDamage( a.getAttackDamage() );
	b.beRepaired(10);
	b.print();
	
	a.guardGate();

	return 0;
}