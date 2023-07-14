/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:55:32 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 11:45:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>
#include <string>

class	AMateria;

class	ICharacter
{
	public:
		virtual ~ICharacter() {}

		virtual std::string	const	&getName() const = 0;
		virtual void				equip( AMateria* m ) = 0;
		virtual void				unequip( int idx ) = 0;
		virtual void				use( int idx, const ICharacter& ic ) = 0;
};

#endif