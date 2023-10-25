/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:20:10 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/25 10:12:34 by minjinki         ###   ########.fr       */
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

int	PmergeMe::_jacobsthal( int n )
{
	if (n == 0)
		return (0);
	else if (n == 1)
		return (1);
	else
		return (_jacobsthal(n - 1) + 2 * _jacobsthal(n - 2));
}

/////////////////////////////////////////////////////////////////

int	PmergeMe::_binaryDeque( int target, int start, int end )
{
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (target == _dqChain[mid])
			return (mid);
		else if (target > _dqChain[mid])
			start = mid + 1;
		else
			end = mid - 1;
	}

	if (target > _dqChain[mid])
		return (mid + 1);
	else
		return (mid);
}

void	PmergeMe::_jacobSeqDeque()
{
	int	idx, size, jacobstal;

	size = _dqPend.size();
	idx = 3;

	jacobstal = _jacobsthal(idx);

	while (jacobstal < size - 1)
	{
		_dqJacob.push_back(jacobstal);
		jacobstal = _jacobsthal(++idx);
	}
}

void	PmergeMe::_generatePosDeque()
{
	int				pos, last;
	unsigned long	tmp;

	if (_dqPend.empty())
		return ;
	
	_jacobSeqDeque();

	last = 1;
	tmp = 1;

	while (!_dqJacob.empty())
	{
		tmp = _dqJacob.front();

		_dqJacob.pop_front();
		_dqPos.push_back(tmp);

		pos = tmp - 1;

		while (pos > last)
		{
			_dqPos.push_back(pos);
			pos--;
		}
		last = tmp;
	}

	while (tmp++ < _dqPend.size())
		_dqPos.push_back(tmp);
}

void	PmergeMe::_insertDeque()
{
	int							target, end, cnt, pos;
	std::deque<int>::iterator	it;

	_generatePosDeque();

	cnt = 0;

	for (it = _dqPos.begin(); it != _dqPos.end(); it++)
	{
		target = _dqPend[*it - 1];

		end = *it + cnt;
		pos = _binaryDeque(target, 0, end);
		_dqChain.insert(_dqChain.begin() + pos, target);
		cnt++;
	}

	if (_dq.size() % 2 != 0)
	{
		target = _dq[_dq.size() - 1];
		pos = _binaryDeque(target, 0, _dqChain.size() - 1);
		_dqChain.insert(_dqChain.begin() + pos, target);
	}
}

void	PmergeMe::_chainDeque()
{
	_dqChain.push_back(_dqPair[0].second);

	for (unsigned long i = 0; i < _dqPair.size(); i++)
	{
		_dqChain.push_back(_dqPair[i].first);
		_dqPend.push_back(_dqPair[i].second);
	}
}

void	PmergeMe::_mergeDeque( int start, int mid, int end )
{
	unsigned long	left, right, merged;

	std::deque< std::pair<int, int> >	leftarr(_dqPair.begin() + start, _dqPair.begin() + mid + 1);
	std::deque< std::pair<int, int> >	rightarr(_dqPair.begin() + mid + 1, _dqPair.begin() + end + 1);

	left = 0;
	right = 0;
	merged = start;

	while (left < leftarr.size() && right < rightarr.size())
	{
		if (leftarr[left].first <= rightarr[right].first)
			_dqPair[merged++] = leftarr[left++];
		else
			_dqPair[merged++] = rightarr[right++];
	}

	while (left < leftarr.size())
		_dqPair[merged++] = leftarr[left++];
	while (right < rightarr.size())
		_dqPair[merged++] = rightarr[right++];
}

void	PmergeMe::_mergeSortDeque( int start, int end )
{
	int	mid;

	if (start >= end)
		return ;
	
	mid = (start + end) / 2;

	_mergeSortDeque(start, mid);
	_mergeSortDeque(mid + 1, end);
	_mergeDeque(start, mid, end);
}

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

void	PmergeMe::_doSortDeque()
{
	if (_dq.size() > 1)
	{
		_createDequePairs();
		_sortDequePairs();
		_mergeSortDeque(0, _dqPair.size() - 1);
		_chainDeque();
		_insertDeque();
	}
	else
		_dqChain.push_back(_dq.front());
}

void	PmergeMe::_sort()
{
	clock_t	start, end;
	double	timeDeque, timeVector;

	start = clock();
	_doSortDeque();
	end = clock();

	timeDeque = static_cast<double>(end - start);

	for (unsigned long i = 0; i < _dqChain.size(); i++)
		std::cout << _dqChain[i] << " ";
	std::cout << std::endl;

	(void)timeDeque;
	(void)timeVector;

	// start = clock();
	// _doSortVector(0, _vec.size() - 1);
	// end = clock();

	// timeVector = static_cast<double>(end - start);

	// _printAfter(timeDeque, timeVector);
}
