/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:09:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/26 13:17:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie	*zombies = new Zombie[N];

	if (N < 0 || !zombies)
		return (NULL);

	for ( int i = 0; i < N; i++ )
		zombies[i].setName(name);

	return ( zombies );
}

// delete []