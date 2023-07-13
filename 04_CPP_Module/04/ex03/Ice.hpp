/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:12:33 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 16:14:19 by minjinki         ###   ########.fr       */
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

		virtual AMateria*	clone() const;
		virtual void		use( ICharacter& target );
}

#endif