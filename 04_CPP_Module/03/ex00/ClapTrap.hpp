/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/27 06:22:56 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define WHITE "\033[0;37m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"

class	ClapTrap
{
	private:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_damage;

		void		_print();
	
	public:
		ClapTrap();
		ClapTrap( const std::string& name );
		ClapTrap( const ClapTrap& ct );
		~ClapTrap();

		// ClapTrap&	operator=( const ClapTrap& ct );
		
		// void	attack( const std::string& target );
		// void	takeDamage( unsigned int amount );
		// void	beRepaired( unsigned int amoutn );
};

#endif
