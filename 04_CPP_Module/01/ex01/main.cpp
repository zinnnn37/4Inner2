/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:10:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/26 13:13:46 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie *zombie;

	zombie = zombieHorde(5, "zombies");

	for (int i = 0; i < 5; i++)
	{
		zombie[i].announce(i);
	}

	delete[] zombie;
	return (0);
}