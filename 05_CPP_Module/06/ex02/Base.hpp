/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:33:40 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 13:50:10 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class	Base
{
	private:

	public:
		virtual ~Base();
};

class	A : public Base {};
class	B : public Base {};
class	C : public Base {};

Base	*generate( void );
void	identify( Base *p );
void	identify( Base &p );

#endif