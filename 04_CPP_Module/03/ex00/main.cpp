/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 17:52:12 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	std::cout << CYAN"==========================================================\n\n";
	std::cout << "                         CLAPTRAP\n\n";
	std::cout << "==========================================================\n\n";
	std::cout << WHITE"----------------------------------------------------------\n" << std::endl;

	ClapTrap	ct;
	ClapTrap	ct2(ct);
	ClapTrap	a("A");
	ClapTrap	b("B");

	a.attack("B");
	b.takeDamage(4);
	b.beRepaired(2);
	b.print();

	b.attack("A");
	a.takeDamage(5);
	a.beRepaired(3);
	a.print();
	
	a.attack("B");
	b.takeDamage(8);
	b.beRepaired(10);
	b.print();

	return 0;
}