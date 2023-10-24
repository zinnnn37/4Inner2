/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:20:10 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/25 08:41:29 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
		*this = pm;

	return (*this);
}

/////////////////////////////////////////////////////////////////

void	PmergeMe::_printBefore()
{
	std::cout << "Before: ";

	for (int i = 1; i < _ac; i++)
		std::cout << _av[i] << " ";

	std::cout << std::endl;
}

void	PmergeMe::_printDeque()
{
	std::cout << "Deque: ";

	for (std::deque<int>::iterator it = _dq.begin(); it != _dq.end(); it++)
		std::cout << *it << " ";
	
	std::cout << std::endl;
}

void	PmergeMe::_printVector()
{
	std::cout << "\nVector: ";

	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::_printAfter( double timeDeque, double timeVector )
{
	std::cout << "\nAfter: " << std::endl;
	_printDeque();
	_printVector();

	std::cout << "\nTime to process a range of " << _dq.size() << " elements with std::deque  : "
		<< timeDeque << "ms" << std::endl;
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector : "
		<< timeVector << "ms" << std::endl;
}

/////////////////////////////////////////////////////////////////

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
				break ;
			else if (!buf.empty() && !_checkValid(buf))
				throw "Invalid input";
			
			_dq.push_back(atoi(buf.c_str()));
			_vec.push_back(atoi(buf.c_str()));
		}
	}
	_printBefore();
}

/////////////////////////////////////////////////////////////////

void	PmergeMe::_sortDequePairs()
{
	int	tmp;

	for (unsigned long i = 0; i < _dqPair.size(); i++)
	{
		if (_dqPair[i].first > _dqPair[i].second)
		{
			tmp = _dqPair[i].first;
			_dqPair[i].first = _dqPair[i].second;
			_dqPair[i].second = tmp;
		}
	}
}

void	PmergeMe::_createDequePairs()
{
	int	i, size;

	i = 0;
	size = _dq.size() / 2;
	while (size > 0)
	{
		_dqPair.push_back(std::make_pair(_dq[i], _dq[i + 1]));
		i += 2;
		size--;
	}
}

void	PmergeMe::_doSortDeque( int start, int end )
{
	(void)start;
	(void)end;
	if (_dq.size() > 1)
	{
		_createDequePairs();
		_sortDequePairs();
		// _mergeSortDeque( 0, _dqPair.size() - 1);
		// _chainDeque();
		// _insertDeque();
	}
	else
		_dqChain.push_back(_dq.front());
}

void	PmergeMe::_sort()
{
	clock_t	start, end;
	double	timeDeque, timeVector;

	start = clock();
	_doSortDeque(0, _dq.size() - 1);
	end = clock();

	timeDeque = static_cast<double>(end - start);

	(void)timeDeque;
	(void)timeVector;

	// start = clock();
	// _doSortVector(0, _vec.size() - 1);
	// end = clock();

	// timeVector = static_cast<double>(end - start);

	// _printAfter(timeDeque, timeVector);
}
