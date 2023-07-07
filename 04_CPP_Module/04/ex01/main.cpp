/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 16:57:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#include <iomanip>

void	test2()
{
	std::cout << CYAN"----------------------------------------" << std::endl;
	std::cout << "\t\ttest_two" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	Animal *ani[100];

	for ( int i = 0; i < 100; i++ )
	{
		if ( i % 2 == 0 )
			ani[i] = new Cat();
		else
			ani[i] = new Dog();
	}

	for ( int i = 0; i < 100; i++ )
	{
		std::cout << WHITE << std::setw(3) << i+1 << ": ";
		ani[i]->makeSound();
	}

	for ( int i = 0; i < 100; i++ )
	{
		delete ani[i];
	}
}

void	test1()
{
	std::cout << CYAN"----------------------------------------" << std::endl;
	std::cout << "\t\ttest_one" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	Cat	*cat = new Cat();
	
	cat->getbrain()->setIdea(WHITE"Idea 1");
	cat->getbrain()->setIdea("Idea 2");
	cat->getbrain()->setIdea("Idea 3");
	std::cout << cat->getbrain()->getIdea(0) << std::endl;
	std::cout << cat->getbrain()->getIdea(1) << std::endl;
	std::cout << cat->getbrain()->getIdea(20) << std::endl;

	delete cat;

	std::cout << std::endl;
}

void	test_sub()
{
	std::cout << CYAN"----------------------------------------" << std::endl;
	std::cout << "\t\ttest_sub" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << i->getType() << std::endl;
	i->makeSound();
	std::cout << j->getType() << std::endl;
	j->makeSound();

	delete i;
	delete j;

	std::cout << std::endl;
}

int main()
{
	test_sub();
	test1();
	test2();
	
	return 0;
}