/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:53:46 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/22 15:20:21 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int	main()
{
	std::cout << "========== Mutant Stack ==========\n";
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\n=============== list ===============\n";

	{
		std::list<int> list;

		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}

	return 0;
}
