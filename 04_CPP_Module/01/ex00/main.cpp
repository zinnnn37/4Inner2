/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:59:41 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/30 11:43:23 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zombie;

	zombie = newZombie("new");
	zombie->announce();
	randomChump("random");

	delete zombie;
}
