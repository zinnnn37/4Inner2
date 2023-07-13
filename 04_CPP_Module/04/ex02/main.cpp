/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/13 13:43:36 by minjinki         ###   ########.fr       */
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

void	test2()
{
	std::cout << CYAN"----------------------------------------" << std::endl;
	std::cout << "\t\ttest_two" << std::endl;
	std::cout << "----------------------------------------\n" << WHITE << std::endl;

	Animal *ani[100];

	for ( int i = 0; i < 100; i++ )
	{
		if ( i % 2 == 0 )
			ani[i] = new Cat();
		else
			ani[i] = new Dog();
	}

	std::cout << std::endl;

	for ( int i = 0; i < 100; i++ )
	{
		std::cout << WHITE << std::setw(3) << i+1 << ": ";
		ani[i]->makeSound();
	}

	std::cout << std::endl;

	for ( int i = 0; i < 100; i++ )
		delete ani[i];

	std::cout << std::endl;
}

void	test1()
{
	std::cout << CYAN"----------------------------------------" << std::endl;
	std::cout << "\t\ttest_one" << std::endl;
	std::cout << "----------------------------------------\n" << std::endl;

	std::cout << CYAN"----------<< Copy Constructor >>----------\n" << WHITE << std::endl;

	Cat	*cat = new Cat();
	
	cat->getBrain()->setIdea(WHITE"Idea 1");
	cat->getBrain()->setIdea("Idea 2");
	cat->getBrain()->setIdea("Idea 3");
	std::cout << "\n" << cat->getBrain()->getIdea(0) << std::endl;
	std::cout << cat->getBrain()->getIdea(1) << std::endl;
	std::cout << cat->getBrain()->getIdea(20) << WHITE"\n" << std::endl;

	Cat	*copycat = new Cat(*cat);

	delete cat;

	std::cout << CYAN"\n*** after delete ***\n" << WHITE << std::endl;

	std::cout << WHITE << copycat->getBrain()->getIdea(0) << std::endl;
	std::cout << copycat->getBrain()->getIdea(1) << std::endl;
	std::cout << copycat->getBrain()->getIdea(20) << WHITE"\n" << std::endl;

	delete copycat;

	std::cout << WHITE << std::endl;

	std::cout << CYAN"------<< Copy Assignment Operator >>------\n" << WHITE << std::endl;

	Dog	*dog1 = new Dog();
	Dog	*dog2 = new Dog();

	dog1->getBrain()->setIdea("Idea 1");
	dog1->getBrain()->setIdea("Idea 2");
	std::cout << WHITE"\n" << dog1->getBrain()->getIdea(0) << std::endl;
	std::cout << dog1->getBrain()->getIdea(1) << "\n" << std::endl;

	*dog2 = *dog1;

	std::cout << std::endl;

	delete dog1;
	
	std::cout << CYAN"\n*** after delete ***\n" << WHITE << std::endl;

	std::cout << WHITE << dog2->getBrain()->getIdea(0) << std::endl;
	std::cout << dog2->getBrain()->getIdea(1) << "\n" << std::endl;

	delete dog2;

	std::cout << WHITE << std::endl;
}

void	test_sub()
{
	std::cout << CYAN"----------------------------------------" << std::endl;
	std::cout << "\t\ttest_sub" << std::endl;
	std::cout << "----------------------------------------\n" << WHITE << std::endl;

	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << WHITE"\n" << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;

	std::cout << std::endl;
}

int main()
{
	atexit(leaks);

	test_sub();
	test1();
	test2();
	
	return 0;
}