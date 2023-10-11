/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:33:31 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/11 14:00:21 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

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
			return (new A());
		case 1:
			return (new B());
		case 2:
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
