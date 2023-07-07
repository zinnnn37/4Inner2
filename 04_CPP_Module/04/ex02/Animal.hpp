/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:39 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 16:19:26 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define WHITE "\033[0;37m"
#define RED "\033[0;31m"
#define CYAN "\033[0;36m"

class	Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal( const Animal& animal );
		virtual	~Animal();
		
		Animal&	operator=( const Animal& animal );

		virtual void	makeSound() const;
		std::string		getType() const;
};

#endif