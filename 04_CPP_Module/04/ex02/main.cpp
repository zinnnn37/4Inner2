/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 14:06:16 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include "Cat.hpp"
#include "Dog.hpp"

#include <stdlib.h>

void	leaks()
{
	system("leaks Animal");
}

int main()
{
	atexit(leaks);

	// Animal	a = Animal();	// allocating an object of abstract class type 'Animal'
	// Animal	*meta = new Animal();	// allocating an object of abstract class type 'Animal'

	Animal	*meta = new Cat();

	std::cout << '\n' << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	delete meta;

	std::cout << std::endl;

	meta = new Dog();

	std::cout << '\n' << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	delete meta;

	std::cout << std::endl;

	return 0;
}