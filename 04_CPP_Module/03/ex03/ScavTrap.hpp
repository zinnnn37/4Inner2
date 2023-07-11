/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:38:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 16:17:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( const std::string name );
		ScavTrap( const ScavTrap& st );
		~ScavTrap();

		ScavTrap&	operator=( const ScavTrap& st );

		void			guardGate();
		unsigned int	getAttackDamage() const;
};

#endif