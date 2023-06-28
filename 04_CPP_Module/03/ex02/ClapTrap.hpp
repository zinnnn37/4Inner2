/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 21:50:30 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/28 13:56:19 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define WHITE "\033[0;37m"
#define BLUE "\033[0;34m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"

class	ClapTrap
{
	protected:	// private으로 설정하면 상속받은 클래스가 사용하지 못함
		std::string		_name;
		int				_hit;
		unsigned int	_energy;
		unsigned int	_damage;
	
	public:
		ClapTrap();
		ClapTrap( const std::string& name );
		ClapTrap( const ClapTrap& ct );
		~ClapTrap();

		ClapTrap&	operator=( const ClapTrap& ct );
		
		void	attack( const std::string& target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amoutn );
		void	print();
};

#endif