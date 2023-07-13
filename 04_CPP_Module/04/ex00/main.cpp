/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 11:38:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <stdlib.h>

void	leaks()
{
	system("leaks Animal");
}

int main()
{
	atexit(leaks);

	std::cout << "----------<< subject test >>----------\n" << std::endl;

	const	Animal* meta = new Animal();
	const	Animal* i = new Cat();
	const	Animal* j = new Dog();
	
	std::cout << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	std::cout << "\n----------<< Wrong Animal >>----------\n" << std::endl;

	const	WrongAnimal* wrongmeta = new WrongAnimal();
	const	WrongAnimal* wrongcat = new WrongCat();

	std::cout << wrongmeta->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongmeta->makeSound();
	wrongcat->makeSound();

	delete wrongmeta;
	delete wrongcat;
	
	std::cout << "\n--------<< Copy Constructor >>--------\n" << std::endl;

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

	std::cout << "\n*** After delete ***\n" << std::endl;

	std::cout << copy.getType() << " " << std::endl;
	copy.makeSound();
	std::cout << copycat.getType() << " " << std::endl;
	copycat.makeSound();
	std::cout << copydog.getType() << " " << std::endl;
	copydog.makeSound();

	std::cout << "\n--------------------------------------\n" << std::endl;

	return 0;
}