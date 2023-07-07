/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 12:02:42 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Animal	copy = Animal(*meta);
	Cat		copycat = Cat(*((Cat*)i));
	Dog		copydog = Dog(*((Dog*)j));

	std::cout << copy.getType() << " " << std::endl;
	copy.makeSound();
	std::cout << copycat.getType() << " " << std::endl;
	copycat.makeSound();
	std::cout << copydog.getType() << " " << std::endl;
	copydog.makeSound();

	delete meta;
	delete i;
	delete j;
	
	std::cout << std::endl << "Copy test" << std::endl;
	std::cout << copy.getType() << " " << std::endl;
	copy.makeSound();
	std::cout << copycat.getType() << " " << std::endl;
	copycat.makeSound();
	std::cout << copydog.getType() << " " << std::endl;
	copydog.makeSound();

	return 0;
}