/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:40:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/16 13:39:28 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private:
		int			_cnt;
		AMateria*	_materia[4];

	public:
		MateriaSource();
		MateriaSource( const MateriaSource& ms );
		~MateriaSource();

		MateriaSource&	operator=( const MateriaSource& ms );

		void			learnMateria( AMateria* m );
		AMateria*		createMateria( std::string const &type );

		const AMateria*	getMateria( int idx ) const;
};

#endif