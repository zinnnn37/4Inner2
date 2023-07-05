/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:10:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/05 18:20:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie *zombies;
	
	zombies = zombieHorde(5, "zombies");

	for (int i = 0; i < 5; i++)
		zombies[i].announce();

	delete[] zombies;
	
	return (0);
}