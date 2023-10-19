/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:22:52 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/19 11:55:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main()
{
	Span	sp = Span(5);

	blue();
	std::cout << "========== subject example ==========\n" << std::endl;
	reset();

	sp.addNumber(6);
	std::cout << "print: ";
	sp.print();

	sp.addNumber(6);
	std::cout << "print: ";
	sp.print();

	std::cout << std::endl;

	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "print: ";
	sp.print();

	std::cout << "\nshortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;

	blue();
	std::cout << "\n========== Exception test ===========\n" << std::endl;
	reset();

	try
	{
		sp.addNumber(1);
	}
	catch(const char *e)
	{
		std::cerr << e << '\n' << std::endl;
		reset();
	}

	try
	{
		Span	ex = Span(3);

		ex.addNumber(1);
		std::cout << ex.shortestSpan() << std::endl;
	}
	catch(const char *e)
	{
		std::cerr << e << '\n';
		reset();
	}

	blue();
	std::cout << "\n========= large number test =========\n" << std::endl;
	reset();

	Span	ex = Span(10000);

	for (int i = 0; i < 10000; i++)
		ex.addNumber(i);
	
	std::cout << "shortest: " << ex.shortestSpan() << std::endl;
	std::cout << "longest: " << ex.longestSpan() << std::endl;

	std::cout << std::endl;

	return 0;
}
