/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:09:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/26 11:51:37 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	if ( N < 0 )
		return (NULL);

	Zombie	*zombies = new Zombie[N];

	if ( !zombies )
		return (NULL);

	for ( int i = 0; i < N; i++ )
		zombies[i].setName(name);

	return ( zombies );
}

// delete []