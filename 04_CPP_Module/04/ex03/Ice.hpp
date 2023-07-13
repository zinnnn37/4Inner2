/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:12:33 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 00:49:58 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice( const Ice &ice );
		virtual ~Ice();

		Ice&	operator=( const Ice &ice );

		AMateria*	clone() const;
		void		use( const ICharacter& c );
};

#endif