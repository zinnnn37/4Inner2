/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 08:05:06 by minjinki          #+#    #+#             */
/*   Updated: 2023/10/26 16:31:05 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>	// or time.h?
#include <sstream>
#include <climits>

class	PmergeMe
{
	private:
		int					_ac;
		char				**_av;

		std::deque<int>						_dq;
		std::deque< std::pair<int, int> >	_dqPair;
		std::deque<int>						_dqChain;
		std::deque<int>						_dqPend;
		std::deque<int>						_dqJacob;
		std::deque<int>						_dqPos;

		std::vector<int>					_vec;
		std::vector< std::pair<int, int> >	_vecPair;
		std::vector<int>					_vecChain;
		std::vector<int>					_vecPend;
		std::vector<int>					_vecJacob;
		std::vector<int>					_vecPos;

		PmergeMe();
		PmergeMe( const PmergeMe &pm );

		PmergeMe	&operator=( const PmergeMe &pm );

		void	_parse();
		void	_sort();

		bool	_checkValid( std::string buf );

		// use pair
		void	_doSortDeque();
		void	_doSortVector();

		void	_createDequePairs();
		void	_createVectorPairs();

		void	_sortDequePairs();
		void	_sortVectorPairs();

		// use pair
		void	_mergeSortDeque( int start, int end );
		void	_mergeSortVector( int start, int end );
		void	_mergeDeque( int start, int mid, int end );
		void	_mergeVector( int start, int mid, int end );

		void	_chainDeque();
		void	_chainVector();

		// use chain
		int		_binaryDeque( int target, int begin, int end );
		int		_binaryVector( int target, int begin, int end );

		void	_insertDeque();
		void	_insertVector();

		void	_jacobSeqDeque();
		void	_jacobSeqVector();

		void	_generatePosDeque();
		void	_generatePosVector();

		int		_jacobsthal( int n );

		void	_printBefore();
		void	_printAfter( double timeDeque, double timeVector );
		void	_printDeque();
		void	_printVector();

	public:
		PmergeMe( int ac, char **av );
		~PmergeMe();
};

#endif