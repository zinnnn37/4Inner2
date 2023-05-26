/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:07:55 by minjinki          #+#    #+#             */
/*   Updated: 2023/05/26 13:13:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie();
		Zombie( std::string _name );
		~Zombie();

		void	announce( int i ); // BraiiiiiiinnnzzzZ...

		/* setter */
		void	setName( std::string _name );
};

Zombie*	zombieHorde( int N, std::string name );

#endif