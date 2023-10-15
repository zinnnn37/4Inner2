/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:33:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/15 14:18:01 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	int	random;

	random = rand() % 3;

	switch (random)
	{
		case 0:
			std::cout << "Class A has been made\n" << std::endl;
			return (new A());
		case 1:
			std::cout << "Class B has been made\n" << std::endl;
			return (new B());
		case 2:
			std::cout << "Class C has been made\n" << std::endl;
			return (new C());
		default:
			return (NULL);
	}
}

void	identify( Base *p )
{
	std::cout << "identify(Base *p) : ";

	if (!p)
	{
		std::cout << "NULL" << std::endl;
		return ;
	}
	
	if (dynamic_cast<A *>(p))
		std::cout << "class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "class C" << std::endl;
}

void	identify( Base &p )
{
	std::cout << "identify(Base &p) : ";

	try
	{
		A	&a = dynamic_cast<A &>(p);
		std::cout << "class A" << std::endl;
		(void)a;
	}
	catch (const std::exception& e)
	{
		try
		{
			B	&b = dynamic_cast<B &>(p);
			std::cout << "class B" << std::endl;
			(void)b;
		}
		catch(const std::exception& e)
		{
			C	&c = dynamic_cast<C &>(p);
			std::cout << "class C" << std::endl;
			(void)c;
		}
	}
}
