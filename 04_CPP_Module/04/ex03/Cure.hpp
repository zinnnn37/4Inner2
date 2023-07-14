/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:14:25 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 12:16:54 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

#define CYAN "\033[0;36m"

class Cure : public AMateria
{
	public:
		Cure();
		Cure( const std::string &type );
		Cure( const Cure &cure );
		virtual ~Cure();

		Cure&	operator=( const Cure &cure );

		AMateria*	clone() const;
		void		use( const ICharacter& c );
};

#endif