/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:53:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 18:57:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

#define WHITE "\033[37m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"

class AMateria
{
	private:
		AMateria();

	protected:
		std::string	_type;

	public:
		AMateria( std::string const &type );
		AMateria( const AMateria& m );
		virtual ~AMateria();

		AMateria&	operator=( const AMateria& m );

		std::string const &getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use( ICharacter& target );
};

#endif