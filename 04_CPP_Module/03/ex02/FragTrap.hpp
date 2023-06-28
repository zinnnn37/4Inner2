/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 12:17:50 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/28 12:21:08 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap( const std::string name );
		FragTrap( const FragTrap& ft );
		~FragTrap();

		FragTrap&	operator=( const FragTrap& ft );

		void	highFivesGuys( void );
}

#endif