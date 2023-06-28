/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/28 13:53:04 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int	main( void )
{
	std::cout << LIME"==========================================================" << std::endl << std::endl;
	std::cout << "                         FRAGTRAP                        " << std::endl << std::endl;
	std::cout << "==========================================================" << std::endl << std::endl;
	std::cout << WHITE"----------------------------------------------------------" << std::endl << std::endl;

	FragTrap	a("A");
	FragTrap	b("B");

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
	
	a.highFivesGuys();

	return 0;
}