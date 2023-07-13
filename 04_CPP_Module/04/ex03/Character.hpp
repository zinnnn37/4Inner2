/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:28 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 19:01:17 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

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
		void				use( int idx, ICharacter& target );
};

#endif