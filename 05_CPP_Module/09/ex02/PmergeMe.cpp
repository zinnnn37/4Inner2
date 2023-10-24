/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:55:44 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/24 20:28:04 by minjinki         ###   ########.fr       */
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
		this->_ac = pm._ac;
		this->_av = pm._av;
		this->_dq = pm._dq;
		this->_vec = pm._vec;
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

void	PmergeMe::_printDeque()
{
	std::cout << "Deque: ";

	for (std::deque<int>::iterator it = _dq.begin(); it != _dq.end(); it++)
		std::cout << *it << " ";
	
	std::cout << std::endl;
}

void	PmergeMe::_printVector()
{
	std::cout << "Vector: ";

	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
}

void	PmergeMe::_printAfter( double timeDeque, double timeVector )
{
	std::cout << "After: " << std::endl;
	_printDeque();
	_printVector();

	std::cout << "Time to process a range of " << _ac - 1 << " elements with std::deque  : "
		<< timeDeque << "ms" << std::endl;
	std::cout << "Time to process a range of " << _ac - 1 << " elements with std::vector : "
		<< timeVector << "ms" << std::endl;
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
	}
	_printBefore();
}

void	PmergeMe::_insertDeque( int start, int end )
{
	int	tmp;
	int	j;

	for (int i = start; i < end; i++)
	{
		tmp = _dq[i + 1];
		j = i + 1;

		while (j > start && _dq[j - 1] > tmp)
		{
			_dq[j] = _dq[j - 1];
			j--;
		}
		_dq[j] = tmp;
	}
}

void	PmergeMe::_insertVector( int start, int end )
{
	int	tmp;
	int	j;

	for (int i = start; i < end; i++)
	{
		tmp = _vec[i + 1];
		j = i + 1;

		while (j > start && _vec[j - 1] > tmp)
		{
			_vec[j] = _vec[j - 1];
			j--;
		}
		_vec[j] = tmp;
	}
}

void	PmergeMe::_mergeDeque( int start, int mid, int end )
{
	int	n1 = mid - start + 1;
	int	n2 = end - mid;
	int	l, r;

	std::deque<int>	left(_dq.begin() + start, _dq.begin() + mid + 1);
	std::deque<int>	right(_dq.begin() + mid + 1, _dq.begin() + end + 1);

	l = 0;
	r = 0;
	for (int i = start; i <= end; i++)
	{
		if (r == n2)
		{
			_dq[i] = left[l];
			l++;
		}
		else if (l == n1)
		{
			_dq[i] = right[r];
			r++;
		}
		else if (left[l] < right[r])
		{
			_dq[i] = left[l];
			l++;
		}
		else
		{
			_dq[i] = right[r];
			r++;
		}
	}
}

void	PmergeMe::_mergeVector( int start, int mid, int end )
{
	int	n1 = mid - start + 1;
	int	n2 = end - mid;
	int	l, r;

	std::vector<int>	left(_vec.begin() + start, _vec.begin() + mid + 1);
	std::vector<int>	right(_vec.begin() + mid + 1, _vec.begin() + end + 1);

	l = 0;
	r = 0;
	for (int i = start; i <= end; i++)
	{
		if (r == n2)
		{
			_vec[i] = left[l];
			l++;
		}
		else if (l == n1)
		{
			_vec[i] = right[r];
			r++;
		}
		else if (left[l] < right[r])
		{
			_vec[i] = left[l];
			l++;
		}
		else
		{
			_vec[i] = right[r];
			r++;
		}
	}
}

void	PmergeMe::_sortDeque( int start, int end )
{
	if (end - start > K)
	{
		int	mid = (start + end) / 2;

		_sortDeque(start, mid);
		_sortDeque(mid + 1, end);
		_mergeDeque(start, mid, end);
	}
	else
		_insertDeque(start, end);
}

void	PmergeMe::_sortVector( int start, int end )
{
	if (end - start > K)
	{
		int	mid = (start + end) / 2;

		_sortVector(start, mid);
		_sortVector(mid + 1, end);
		_mergeVector(start, mid, end);
	}
	else
		_insertVector(start, end);
}

void	PmergeMe::_sort()
{
	clock_t	start, end;
	double	timeDeque, timeVector;

	start = clock();
	_sortDeque(0, _dq.size() - 1);
	end = clock();

	timeDeque = 1000.0 * (end - start) / CLOCKS_PER_SEC;

	start = clock();
	_sortVector(0, _vec.size() - 1);
	end = clock();

	timeVector = 1000.0 * (end - start) / CLOCKS_PER_SEC;

	_printAfter(timeDeque, timeVector);
}
