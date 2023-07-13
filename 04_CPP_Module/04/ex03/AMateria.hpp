/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:53:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/14 00:52:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define WHITE "\033[0;37m"
#define PURPLE "\033[0;35m"

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