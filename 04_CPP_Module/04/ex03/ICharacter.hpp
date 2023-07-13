/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:55:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 17:04:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

class	ICharacter
{
	private:
		std::string	_name;
		AMateria*	_materia[4];

		ICharacter();

	public:
		ICharacter( std::string name );
		ICharacter( const ICharacter& c );
		virtual ~ICharacter() {}

		ICharacter&	operator=( const ICharacter& c );

		virtual std::string	const &getName() const = 0;
		virtual void		equip( AMateria* m ) = 0;
		virtual void		unequip( int idx ) = 0;
		virtual void		use( int idx, ICharacter& target ) = 0;
}

#endif