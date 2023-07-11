/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:23 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 17:30:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	std::cout << PURPLE"==========================================================\n\n";
	std::cout << "                       DIAMONDTRAP                     \n\n";
	std::cout << "==========================================================\n\n";
	std::cout << WHITE"----------------------------------------------------------\n" << std::endl;

	DiamondTrap	a( "A" );

	a.whoAmI();

	return 0;
}
// virtual 상속 사용하면 문제 해결된다고 함