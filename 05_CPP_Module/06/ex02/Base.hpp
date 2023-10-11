/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:33:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 13:35:57 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>

class	Base
{
	private:

	public:
		Base();
		Base( const Base &b );
		virtual ~Base();

		Base	&operator=( const Base &b );

		Base	*generate( void );
		void	identify( Base *p );
		void	identify( Base &p );
};

#endif