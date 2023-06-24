/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:44:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/24 10:52:33 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;

	public:
		HumanB( std::string _name );
		~HumanB();

		void	attack( void ) const;
		void	setWeapon( Weapon &weapon );
};

#endif