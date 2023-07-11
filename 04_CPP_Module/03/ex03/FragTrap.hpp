/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:17:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/11 23:58:20 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap( const std::string name );
		FragTrap( const FragTrap& ft );
		~FragTrap();

		FragTrap&	operator=( const FragTrap& ft );

		void			highFivesGuys( void );
		unsigned int	getAttackDamage() const;
};

#endif