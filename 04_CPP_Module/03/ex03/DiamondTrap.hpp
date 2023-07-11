/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:58:37 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/12 00:21:30 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
#define DIAMOND_TRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	_name;
		
	public:
		DiamondTrap();
		DiamondTrap( const std::string name );
		DiamondTrap( const DiamondTrap& dt );
		~DiamondTrap();

		DiamondTrap&	operator=( const DiamondTrap& dt );

		void	whoAmI();
};

#endif