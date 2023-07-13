/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:25:12 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 12:17:53 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain*	_brain;

	public:
		Cat();
		Cat( const Cat& cat );
		~Cat();

		Cat&	operator=( const Cat& cat );

		void	makeSound() const;
		Brain*	getBrain() const;
};

#endif