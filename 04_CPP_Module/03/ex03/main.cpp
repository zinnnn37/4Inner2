/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/12 00:28:05 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	std::cout << PURPLE"==========================================================\n\n";
	std::cout << "                       DIAMONDTRAP\n\n";
	std::cout << "==========================================================\n\n";
	std::cout << WHITE"----------------------------------------------------------\n" << std::endl;

	DiamondTrap	a( "A" );
	DiamondTrap	b;

	a.print();
	a.whoAmI();

	b.whoAmI();

	a.attack("B");
	a.takeDamage(4);
	a.beRepaired(2);
	a.print();

	return 0;
}
// virtual 상속 사용하면 문제 해결된다고 함