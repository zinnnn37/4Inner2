/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:53:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 12:17:27 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define WHITE "\033[0;37m"
#define BLUE "\033[0;34m"

class AMateria
{
	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria( std::string const &type );
		AMateria( const AMateria& m );
		virtual ~AMateria();

		AMateria&	operator=( const AMateria& m );

		std::string const&	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( const ICharacter& c );
};

#endif