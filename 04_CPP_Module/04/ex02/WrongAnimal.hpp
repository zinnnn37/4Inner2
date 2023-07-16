/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:26:08 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/16 12:53:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal& animal );
		virtual ~WrongAnimal();

		WrongAnimal&	operator=( const WrongAnimal& animal );

		void		makeSound() const;
		std::string	getType() const;
};

#endif