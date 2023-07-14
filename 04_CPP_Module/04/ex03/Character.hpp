/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:28 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 11:45:21 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define WHITE "\033[0;37m"
#define YELLOW "\033[33m"

#include "ICharacter.hpp"
#include "AMateria.hpp"

class	Character : public ICharacter
{
	private:
		std::string	_name;

		int			_idx;
		AMateria*	_slot[4];
	
	public:
		Character();
		Character( std::string name );
		Character( const Character& c );
		~Character();

		Character&	operator=( const Character& c );

		std::string const	&getName() const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, const ICharacter& ic );

		const AMateria*		getMateria( int idx ) const;
};

#endif