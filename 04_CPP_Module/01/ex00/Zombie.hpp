/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:31:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/30 11:43:15 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string _name;

	public:
		Zombie( std::string name );
		~Zombie();
		
		void	announce( void ); // BraiiiiiiinnnzzzZ...
		
};

Zombie	*newZombie( std::string name ); // make zombie and return zombie
void	randomChump( std::string name ); // make zombie(call newZombie) and announce

#endif
