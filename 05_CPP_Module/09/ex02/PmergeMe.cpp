/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:55:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 18:48:43 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe( int ac, char **av )
	: _ac(ac), _av(av)
{
	_parse();
	_sort();
}

PmergeMe::PmergeMe( const PmergeMe &pm )
{
	*this = pm;
}

PmergeMe::~PmergeMe() {}

PmergeMe	&PmergeMe::operator=( const PmergeMe &pm )
{
	if (this != &pm)
	{
		_av = pm._av;
		_dq = pm._dq;
		_vec = pm._vec;
	}
	return (*this);
}

void	PmergeMe::_printBefore()
{
	std::cout << "Before: ";

	for (int i = 1; i < _ac; i++)
		std::cout << _av[i] << " ";

	std::cout << std::endl;
}

bool	PmergeMe::_checkValid( std::string buf )
{
	char	*end;
	long	l = strtol(buf.c_str(), &end, 10);

	if (*end != '\0' || l > INT_MAX || l < 0)
		return (false);
	
	return (true);
}

void	PmergeMe::_parse()
{
	std::string	buf;

	for (int i = 1; i < _ac; i++)
	{
		std::stringstream	ss(_av[i]);

		while (getline(ss, buf, ' '))
		{
			if (buf.empty())
				continue ;
			else if (!buf.empty() && !_checkValid(buf))
				throw "Invalid input";
			
			_dq.push_back(atoi(buf.c_str()));
			_vec.push_back(atoi(buf.c_str()));
		}
		i++;
	}
	_printBefore();
}

void	PmergeMe::_sort()
{
	
}
