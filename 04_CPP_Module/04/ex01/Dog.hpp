/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:26:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 12:18:03 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	private:
		Brain*	_brain;

	public:
		Dog();
		Dog( const Dog& dog );
		~Dog();

		Dog&	operator=( const Dog& dog );
		
		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif