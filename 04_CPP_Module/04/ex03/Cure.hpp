/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:14:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 16:29:53 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure( const Cure &cure );
		virtual ~Cure();

		Cure&	operator=( const Cure &cure );

		virtual AMateria*	clone() const;
		virtual void		use( ICharacter& target );
}

#endif