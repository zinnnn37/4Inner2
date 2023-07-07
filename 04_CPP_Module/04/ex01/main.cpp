/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 14:24:19 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/07 15:48:09 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

void	test()
{
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
		delete ani[i];
	}
}

void	test1()
{
	Cat	*cat = new Cat();
	
	cat->getbrain()->setIdea("Idea 1");
	cat->getbrain()->setIdea("Idea 2");
	cat->getbrain()->setIdea("Idea 3");
	std::cout << cat->getbrain()->getIdea(0) << std::endl;
	std::cout << cat->getbrain()->getIdea(1) << std::endl;
	std::cout << cat->getbrain()->getIdea(2) << std::endl;

	delete cat;
}

void	test_sub()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();

	std::cout << i->getType() << std::endl;
	i->makeSound();
	std::cout << j->getType() << std::endl;
	j->makeSound();

	delete i;
	delete j;
}

int main()
{
	//test_sub();
	test1();
	//test();
	
	return 0;
}