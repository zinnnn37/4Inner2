/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/06/30 16:04:35 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal( const Animal& animal );
		virtual	~Animal();
		
		Animal&	operator=( const Animal& animal );

		virtual void	makeSound();
};

#endif