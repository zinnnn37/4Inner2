/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:10:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/26 13:19:49 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie *zombies;

	zombies = zombieHorde(5, "zombies");
	if (!zombies)
		return (1);

	for (int i = 0; i < 5; i++)
		zombies[i].announce(i);

	delete[] zombies;
	
	return (0);
}