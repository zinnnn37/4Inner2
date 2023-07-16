/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/16 13:03:40 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#define WHITE "\033[0;37m"
#define CYAN "\033[0;36m"

#include <stdlib.h>

void	leaks()
{
	system("leaks Animal");
}

int main()
{
	atexit(leaks);

	std::cout << CYAN"----------<< subject test >>----------\n" << WHITE << std::endl;

	const Animal*	meta = new Animal();
	const Animal*	i = new Cat();
	const Animal*	j = new Dog();
	//const Cat*		test = new Animal();
	
	std::cout << "\n" << meta->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << CYAN"\n----------<< Wrong Animal >>----------\n" << WHITE << std::endl;

	const	WrongAnimal* wrongmeta = new WrongAnimal();
	const	WrongAnimal* wrongcat = new WrongCat();

	std::cout << "\n" << wrongmeta->getType() << " " << std::endl;
	std::cout << wrongcat->getType() << " " << std::endl;
	wrongmeta->makeSound();
	wrongcat->makeSound();

	std::cout << std::endl;

	delete wrongmeta;
	delete wrongcat;

	return 0;
}